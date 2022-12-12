import numpy as np
import cv2
import matplotlib.pyplot as plt
import math

def dnorm(x, mu, sd):
    return 1 / (np.sqrt(2 * np.pi) * sd) * np.e ** (-np.power((x - mu) / sd, 2) / 2)


def gaussian_kernel(tam, sigma=1):
    kernel_1D = np.linspace(-(tam // 2), tam // 2, tam)
    for i in range(tam):
        kernel_1D[i] = dnorm(kernel_1D[i], 0, sigma)
    kernel_2D = np.outer(kernel_1D.T, kernel_1D.T)

    kernel_2D *= 1.0 / kernel_2D.max()

    return kernel_2D


def gaussian_blur(img, kernel_size):
    kernel = gaussian_kernel(kernel_size, sigma=math.sqrt(kernel_size))
    return convolution(img, kernel, media=True)

def convolution(img, kernel, media=False):
    if len(img.shape) == 3:
        img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    img_linha, img_coluna = img.shape
    kernel_linha, kernel_coluna = kernel.shape

    saida = np.zeros(img.shape)

    pad_height = int((kernel_linha - 1) / 2)
    pad_width = int((kernel_coluna - 1) / 2)

    padded_image = np.zeros((img_linha + (2 * pad_height), img_coluna + (2 * pad_width)))

    padded_image[pad_height:padded_image.shape[0] - pad_height, pad_width:padded_image.shape[1] - pad_width] = img

    for linha in range(img_linha):
        for coluna in range(img_coluna):
            saida[linha, coluna] = np.sum(kernel * padded_image[linha:linha + kernel_linha, coluna:coluna + kernel_coluna])
            if media:
                saida[linha, coluna] /= kernel.shape[0] * kernel.shape[1]

    return saida
    
def sobel_edge_detection(img, filtro):
    img_x = convolucao(img, filtro)

    img_y = convolucao(img, np.flip(filtro.T, axis=0))

    gradiente = np.sqrt(np.square(img_x) + np.square(img_y))

    gradiente *= 255.0 / gradiente.max()


    return gradiente








def main():
    # Algoritmo 1
    # filtro = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]]) # vertical

    # img = cv2.imread('/Users/douglasgondim/Documents/college-2022.1/Numerical Methods II/assignment1.2/fruits.jpeg')

    # img = gaussian_blur(img, 9)
    # plt.imshow(img, cmap="gray")
    # plt.show()
    # img = sobel_edge_detection(img, filtro)


    # plt.imshow(img, cmap='gray_r')
    # plt.title("Bordas Detectadas")
    # plt.show()

    #Algoritmo 2
    # source = cv2.imread('/Users/douglasgondim/Documents/college-2022.1/Numerical Methods II/assignment1.2/fruits.jpeg', cv2.IMREAD_COLOR)

    # source = cv2.GaussianBlur(source, (3, 3), 0)
    
    # source_gray = cv2.cvtColor(source, cv2.COLOR_BGR2GRAY)

    # plt.imshow(source_gray, cmap="gray")
    # plt.show()

    # dest = cv2.Laplacian(source_gray, cv2.CV_16S, ksize=3)
    # abs_dest = cv2.convertScaleAbs(dest)
    # plt.imshow(abs_dest, cmap="gray")
    # plt.show()

    img = cv2.imread('/Users/douglasgondim/Documents/college-2022.1/Numerical Methods II/assignment1.2/fruits.jpeg')

    img = gaussian_blur(img, 9)

    laplace1 = np.array([[0, -1, 0], [-1, 4, -1], [0, -1, 0]])
    laplace2 = np.array([[-1, -1, -1], [-1, 8, -1], [-1, -1, -1]])

    image_arr5 = convolution(img, laplace1)

    image_arr6 = np.zeros((image_arr5.shape))
    #Aplicando o treshold
    for i in range(image_arr5.shape[0]):
        for j in range(image_arr5.shape[0]):
            if abs(image_arr5[i, j]) >= 0.045:
                image_arr6[i, j] = 1.0
            else:
                image_arr6[i, j] = 0.0
    finalImg = np.zeros((image_arr6.shape[0], image_arr6.shape[1], 3))
    finalImg[0:finalImg.shape[0], 0:finalImg.shape[1],0] = image_arr6
    finalImg[0:finalImg.shape[0], 0:finalImg.shape[1],1] = image_arr6
    finalImg[0:finalImg.shape[0], 0:finalImg.shape[1],2] = image_arr6

    plt.imshow(finalImg, interpolation='nearest')
    plt.show()

    image_arr7 = convolution(img, laplace2)

    image_arr8 = np.zeros((image_arr5.shape))
    #Aplicando o treshold
    for i in range(image_arr7.shape[0]):
        for j in range(image_arr7.shape[0]):
            if abs(image_arr7[i, j]) >= 0.1:
                image_arr8[i, j] = 1.0
            else:
                image_arr8[i, j] = 0.0
    finalImg = np.zeros((image_arr8.shape[0], image_arr8.shape[1], 3))
    finalImg[0:finalImg.shape[0], 0:finalImg.shape[1],0] = image_arr8
    finalImg[0:finalImg.shape[0], 0:finalImg.shape[1],1] = image_arr8
    finalImg[0:finalImg.shape[0], 0:finalImg.shape[1],2] = image_arr8

    plt.imshow(finalImg, interpolation='nearest')
    plt.show()


main()