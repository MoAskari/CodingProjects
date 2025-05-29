%% Task 1
clc;
clear;

% Design 20th order FIR lowpass filter
M1 = 20;
Fp1 = 0.5;
b1 = fir1(M1, Fp1);

% Design 60th order FIR lowpass filter
M2 = 60;
Fp2 = 0.5;  
b2 = fir1(M2, Fp2);

% Plot the frequency responses using 512 points
[H1, w1] = freqz(b1, 1, 512);
[H2, w2] = freqz(b2, 1, 512);

% Convert to magnitude (dB)
mag1 = 20 * log10(abs(H1));
mag2 = 20 * log10(abs(H2));

% Plot the graphs
figure;
plot(w1/pi, mag1, 'b', 'LineWidth', 1.5); hold on;
plot(w2/pi, mag2, 'r', 'LineWidth', 1.5);
xlim([0 1]);
ylim([-80 5]);
xlabel('Normalized Frequency');
ylabel('Magnitude (dB)');
title('Frequency Response of 20th and 60th Order FIR Lowpass Filters');
legend('FIR N = 20', 'FIR N = 60');
grid on;

%% Task 2

% Calculate the group delays for both filters
[Gd1, w] = grpdelay(b1, 1, 512);
[Gd2, ~] = grpdelay(b2, 1, 512);

% Calculate the phase responses for both filters
[H1, w1] = freqz(b1, 1, 512);
[H2, w2] = freqz(b2, 1, 512);
phase1 = unwrap(angle(H1));
phase2 = unwrap(angle(H2));

% Plot the group delays and phase responses
figure;
% Group Delay plot
subplot(2, 1, 1);
plot(w/pi, Gd1, 'b', w/pi, Gd2, 'r');
xlabel('Normalized frequency (x pi rad/sample)');
ylabel('Group delay (samples)');
title('Group Delay');
legend('20th order FIR lowpass filter', '60th order FIR lowpass filter');
ylim([0, 35]);

% Phase Response plot
subplot(2, 1, 2);
plot(w1/pi, phase1, 'b', w2/pi, phase2, 'r');
xlabel('Normalized frequency (x pi rad/sample)');
ylabel('Phase (radians)');
title('Phase response');
legend('20th order FIR lowpass filter', '60th order FIR lowpass filter');
ylim([-60, 0]);

%% Task 3
% Filter order
M = 60;

% Design filters using different window functions
hamming_filter = fir1(M, 0.01, 'low', hamming(M+1));
hann_filter = fir1(M, 0.01, 'low', hann(M+1));
blackman_filter = fir1(M, 0.01, 'low', blackman(M+1));

% Plot time domain window functions
figure;
subplot(1, 2, 1);
plot(0:M, hamming(M+1), 'DisplayName', 'Hamming');
hold on;
plot(0:M, hann(M+1), 'DisplayName', 'Hann');
plot(0:M, blackman(M+1), 'DisplayName', 'Blackman');
hold off;

title('Time domain');
xlabel('Samples');
ylabel('Amplitude');
xlim([0 60]);
ylim([0 1.1]);
legend('Location', 'northeast');

% Plot frequency domain responses
subplot(1, 2, 2);
[H_hamming, w] = freqz(hamming_filter, 1, 512);
H_hann = freqz(hann_filter, 1, 512);
H_blackman = freqz(blackman_filter, 1, 512);

plot(w/pi, 20*log10(abs(H_hamming)), 'DisplayName', 'Hamming');
hold on;
plot(w/pi, 20*log10(abs(H_hann)), 'DisplayName', 'Hann');
plot(w/pi, 20*log10(abs(H_blackman)), 'DisplayName', 'Blackman');
hold off;

title('Frequency domain');
xlabel('Normalized frequency (x pi rad/sample)');
ylabel('Magnitude (dB)');  
xlim([0 1]);
ylim([-140 40]);
legend('Location', 'southwest');
