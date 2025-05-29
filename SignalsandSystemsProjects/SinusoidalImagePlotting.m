%% Task 1
clear;
clc;

% Generate a random image
A=reshape(rand(10000, 1), [100, 100]);
A = A * 255; % Adjust the values to 0-255

% Display the image with 256 gray levels
figure;
image(A);
colormap(gray(256));
colorbar;
title('Image with 256 gray levels');

% Show the same image with 16 gray levels
figure;
image(A);
colormap(gray(16));
colorbar;
title('Image with 16 gray levels');

% Load the vertebra.png image
B = imread('vertebra.png');

% Show the vertebra.png image
figure;
image(B);
colormap(gray(256));
colorbar;
title('Vertebra Image');

% Show the histogram of the vertebra.png image
figure;
imhist(B);
title('Histogram of Vertebra Image');
ylabel('Pixel Count');

%% Task 2
% Load the image
img = imread('vertebra.png');

% Convert the RGB image to grayscale if necessary
if size(img, 3) == 3
img = rgb2gray(img);
end

% Adjust the contrast of the image
img_adj = imadjust(img);

% Display the original image
figure;
subplot(1, 2, 1);
imshow(img);
title('Original Image');

% Display the contrast adjusted image
subplot(1, 2, 2);
imshow(img_adj);
title('Contrast Adjusted Image');

% Plot the histogram of the new image
figure;
imhist(img_adj);
title('Histogram of Contrast Adjusted Image');
xlabel('Pixel Count');
ylabel('Grey Level');
%% Task 3

% Define an image with well-defined sinusoidal frequencies
N = 128;
xfreq = 0.1;
yfreq = 0.1;
n = 0:N-1;
xvalues = sin(2*pi*xfreq*n);
myimage = xvalues'*yvalues;

% Plot the sinusoids used to create the image
figure;
plot(n, xvalues); % Plotting xvalues
title('Sinusoids used for x and y axes');
xlabel('Data points');
ylabel('Amplitude');

% (a) Plot the image
figure;
imagesc(myimage);
colormap(gray);
colorbar;
title('Sinusoidal Image');

% (a.1) Display the image with imshow and gray colormap with 256 gradients
figure;
imshow(myimage, 'Colormap', gray(256));
title('Sinusoidal Image Displayed with imshow');

% (b) Calculate the two-dimensional Fourier transform of the image
F = fft2(myimage);

% Shift zero-frequency components to center
Fshift = fftshift(F);

% Calculate the magnitude of the Fourier transform
magF = abs(Fshift);

% Convert to binary image using a threshold
threshold = max(magF(:)) * 0.5; % Set threshold as 50% of the max value, adjust as needed
binaryF = magF > threshold; % Any value greater than threshold is 1, else 0

% Plot the magnitude of the Fourier transform of the image
figure;
imagesc(binaryF);
colormap(gray);
colorbar;
title('Magnitude of Fourier Transform of Sinusoidal Image');

