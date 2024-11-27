import numpy as np
import cv2

def bilinear_interpolation(img, x, y):
    h, w = img.shape
    x_int = int(np.floor(x))
    y_int = int(np.floor(y))

    x_int = min(max(x_int, 0), w - 2)
    y_int = min(max(y_int, 0), h - 2)

    h1 = y - y_int
    h2 = 1 - h1
    w1 = x - x_int
    w2 = 1 - w1

    alpha = h1 / (h1 + h2) if (h1 + h2) != 0 else 0.5
    beta = h2 / (h1 + h2) if (h1 + h2) != 0 else 0.5
    p = w1 / (w1 + w2) if (w1 + w2) != 0 else 0.5
    q = w2 / (w1 + w2) if (w1 + w2) != 0 else 0.5

    A = img[y_int, x_int]
    B = img[y_int, x_int + 1]
    C = img[y_int + 1, x_int]
    D = img[y_int + 1, x_int + 1]

    P = q * (beta * A + alpha * B) + p * (beta * D + alpha * C)

    return np.clip(P, 0, 255)

def cubic_kernel(d, a=-0.5):
    d = abs(d)
    if d <= 1:
        return (a + 2) * (d ** 3) - (a + 3) * (d ** 2) + 1
    elif d < 2:
        return a * (d ** 3) - 5 * a * (d ** 2) + 8 * a * d - 4 * a
    else:
        return 0

def bicubic_interpolation(img, x, y):
    h, w = img.shape
    x_int = int(np.floor(x))
    y_int = int(np.floor(y))

    result = 0.0
    for m in range(-1, 3):
        for n in range(-1, 3):
            x_neigh = min(max(x_int + m, 0), w - 1)
            y_neigh = min(max(y_int + n, 0), h - 1)
            pixel_value = img[y_neigh, x_neigh]

            weight_x = cubic_kernel(x - (x_int + m))
            weight_y = cubic_kernel(y - (y_int + n))

            result += pixel_value * weight_x * weight_y

    return np.clip(result, 0, 255)

def main():
    image = cv2.imread("home.jpg", cv2.IMREAD_GRAYSCALE)

    new_w, new_h = 800, 600
    scale_x = image.shape[1] / new_w
    scale_y = image.shape[0] / new_h

    bilinear_image = np.zeros((new_h, new_w), dtype=np.uint8)
    bicubic_image = np.zeros((new_h, new_w), dtype=np.uint8)

    for i in range(new_h):
        for j in range(new_w):
            x = j * scale_x
            y = i * scale_y
            bilinear_image[i, j] = bilinear_interpolation(image, x, y)
            bicubic_image[i, j] = bicubic_interpolation(image, x, y)

    result = cv2.hconcat([bilinear_image, bicubic_image])

    cv_bilinear = cv2.resize(image, (new_w, new_h), interpolation=cv2.INTER_LINEAR)
    cv_bicubic = cv2.resize(image, (new_w, new_h), interpolation=cv2.INTER_CUBIC)

    cv_result = cv2.hconcat([cv_bilinear, cv_bicubic])
    compare_result = cv2.vconcat([result, cv_result])

    cv2.imshow("Interpolation Result", compare_result)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
