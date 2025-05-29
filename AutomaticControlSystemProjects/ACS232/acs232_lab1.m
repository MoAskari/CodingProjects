%%  ACS232 Analog Modulation Lab, University of Sheffield - Spring 2019
clear variables;
close all;
%% System Parameters

% Message signal parameters
ts=5e-4;                                                                                                                            % Sampling interval
T=0.15;                                                                                                                             % Message signal time duration
% Modulation parameters
fc=250;                                                                                                                             % Frequency of the carrier
a=0.85;                                                                                                                             % Modulation signal     
% Frequency representation parameters
df=0.1;                                                                                                                             % Frequency resolution to plot Fourier transform
%% Message signal construction and plot against normalised signal (1.1)

t=0:ts:T;                                                                                                                           % Time indices for signal representation
m=[ones(1,floor(length(t)/3)) -2*ones(1,floor(length(t)/3)) zeros(1,ceil(length(t)/3))];                                            % Message signal construction
mnorm = m/max(abs(m));                                                                                                              % Construction of the normalised message signal

figure;                                                                                                                             % Creates a new message signal
subplot(6,2,1)                                                                                                                      % Creates a new subplot
plot(t,m)                                                                                                                           % Plots message signal against time                                                                                      % Sets the graph to                         
xlabel('time')                                                                                                                      % Labels x axis of the plot
ylabel('signal amplitude')                                                                                                          % Labels y axis of the plot
axis([0 T -3 3])                                                                                                                    % Sets the axis limits shown on the x and y axes

hold on                                                                                                                             % Retains the next plot in the current axes
plot(t,mnorm)                                                                                                                       % Plots normalised message signal against time
title('Message signal m(t) in time domain (with normalisation) (1.1)')                                                              % Labels the plot

% Fourier Transform: Uses the fourier transform function to return the transform of the discrete time signal M
% Inputs taken are of the discrete time signal, the time interval and desired frequency interval (m, ts, df)
% Outputs given are fourier transform, the frequencies for which the transform is evaluated in M, and the frequency interval used (M, freq_M, df_M)
[M,freq_M, df_M]=fourier_transform(m,ts,df);
subplot(6,2,2)                                                                                                                      % Creates a new subplot
plot(freq_M,abs(M));                                                                                                                % Plots the absolute value of the fourier transform of M against it's frequency
xlabel('frequency')                                                                                                                 % Labels x axis of the plot
ylabel('M(f)')                                                                                                                      % Labels y axis of the plot
axis([-1000 1000 0 0.15])                                                                                                           % Sets the axis limits shown on the x and y axes
title('Spectrum of Message signal in frequency domain (1.1)')                                                                       % Labels the plot

%% Carrier signal construction and plot (1.2)

Ac = 1;                                                                                                                             % Defines the carrier signal amplitude
c = Ac.*cos(2.*pi.*fc.*t);                                                                                                          % Defines the carrier signal, with frequency 250 Hz, and Ac = 1

subplot(6,2,3)                                                                                                                      % Creates a new subplot
plot(t,c)                                                                                                                           % Plots the carrier signal against time
xlabel('time')                                                                                                                      % Labels x axis of the plot
ylabel('signal amplitude')                                                                                                          % Labels y axis of the plot
axis([0 T -3 3])                                                                                                                    % Sets the axis limits shown on the x and y axes
title('Carrier signal c(t) in time domain (1.2)')                                                                                   % Labels the plot

[C,freq_C, df_C]=fourier_transform(c,ts,df);                                                                                        % Computes the fourier transform of the carrier signal
subplot(6,2,4)                                                                                                                      % Creates a new subplot
plot(freq_C,abs(C));                                                                                                                % Plots the absolute value of the fourier transform of the carrier against it's frequency
xlabel('frequency')                                                                                                                 % Labels x axis of the plot
ylabel('C(f)')                                                                                                                      % Labels y axis of the plot
axis([-1000 1000 0 0.1])                                                                                                            % Sets the axis limits shown on the x and y axes
title('Spectrum of Carrier signal in frequency domain (1.2)')                                                                       % Labels the plot
%% Conventional AM modulated signal construction and plot (1.2)

uc=(1+(a.*mnorm)).*c;                                                                                                               % Defines the Conventional AM modulated signal (without carrier suppression) using the normalised message signal and carrier signal

subplot(6,2,5)                                                                                                                      % Creates a new subplot
plot(t,uc)                                                                                                                          % Plots the conventional AM modulated signal against time
xlabel('time')                                                                                                                      % Labels x axis of the plot
ylabel('Uc(t)')                                                                                                                     % Labels y axis of the plot
axis([0 T -3 3])                                                                                                                    % Sets the axis limits shown on the x and y axes
title('Conventional AM Modulated Signal in time domain (1.2)')                                                                      % Labels the plot

subplot(6,2,6)                                                                                                                      % Creates a new subplot
[UC,freq_UC, df_UC]=fourier_transform(uc,ts,df);                                                                                    % Computes the fourier transform of the conventional AM modulated signal
plot(freq_UC,abs(UC));                                                                                                              % Plots the absolute value of the fourier transform of the conventional AM modulated signal against it's frequency
xlabel('frequency')                                                                                                                 % Labels x axis of the plot
ylabel('Uc(f)')                                                                                                                     % Labels y axis of the plot
axis([-1000 1000 0 0.1])                                                                                                            % Sets the axis limits shown on the x and y axes
title('Spectrum of the conventional AM modulated signal in the frequency domain (1.2)')                                             % Labels the plot
%% Double Sideband Supressed-Carrier (DSB-SC) Analog Modulated Signal construction and plot (1.3)

ud = m.*c;                                                                                                                          % Defines the DSB-SC analog modulated signal as the product of the message and carrier signals

subplot(6,2,7)                                                                                                                      % Creates a new subplot
plot(t,ud)                                                                                                                          % Plots the DSB-SC analog modulated signal against time
title('Double Sideband Supressed-Carrier (DSB-SC) Analog Modulated Signal in time domain (1.3)')                                    % Labels the plot
xlabel('time')                                                                                                                      % Labels x axis of the plot
ylabel('Ud(t)')                                                                                                                     % Labels y axis of the plot
axis([0 0.15 -2.5 2.5])                                                                                                             % Sets the axis limits shown on the x and y axes

subplot(6,2,8)                                                                                                                      % Creates a new subplot
[UD,freq_UD, df_UD]=fourier_transform(ud,ts,df);                                                                                    % Computes the fourier transform of the DSB-SC analog modulated signal
plot(freq_UD,abs(UD));                                                                                                              % Plots the absolute value of the fourier transform of the DSB-SC modulated signal against it's frequency
xlabel('frequency')                                                                                                                 % Labels x axis of the plot
ylabel('M(f)C(f) or Ud(f)')                                                                                                          % Labels y axis of the plot
axis([-1000 1000 0 0.06])                                                                                                           % Sets the axis limits shown on the x and y axes
title('Spectrum of the Double Sideband Suppressed modulated signal in the frequency domain (1.3)')                                  % Labels the plot
%% DSB-SC AM Modulated signal mixed with carrier, construction and plot (2.1)

y = ud.*c;                                                                                                                          % Defines y, a mix of the DSB-SC and carrier signals

subplot(6,2,9)                                                                                                                      % Creates a new subplot
plot(t,y)                                                                                                                           % Plots the mix of the DSB-SC and carrier signal against time
xlabel('time')                                                                                                                      % Labels x axis of the plot
ylabel('signal amplitude')                                                                                                          % Labels y axis of the plot
axis([0 0.15 -2.5 2.5])                                                                                                             % Sets the axis limits shown on the x and y axes
title('Double Sideband Suppressed modulated signal mixed with the carrier signal in the time domain (2.1)')                         % Labels the plot

subplot(6,2,10)                                                                                                                     % Creates a new subplot
[Y,freq_y, df_y]=fourier_transform(y,ts,df);                                                                                        % Computes the fourier transform of y
plot(freq_y,abs(Y));                                                                                                                % Plots the absolute value of the fourier transform of y against it's frequency
xlabel('frequency')                                                                                                                 % Labels x axis of the plot
ylabel('M(f)')                                                                                                                      % Labels y axis of the plot
axis([-1000 1000 0 0.06])                                                                                                           % Sets the axis limits shown on the x and y axes
title('Spectrum of the Double Sideband Suppressed modulated signal mixed with the carrier signal in the frequency domain (2.1)')    % Labels the plot
%% Freqency response of the ideal lowpass filter (2.2)

f_cutoff1 = 100;                                                                                                                    % Defines the cutoff frequency of the ideal lowpass filter
H_max = 1.85;                                                                                                                       % Defines the gain used to demodulate the DSB-SC signal

unitstep = zeros(size(freq_y));                                                                                                     % Produces a unit step signal using the frequencies of the signal y 
unitstep(freq_y >= -f_cutoff1)= H_max;                                                                                              % Defines the unit step signal to be 1.85 when the frequency is >= -100
unitstep(freq_y >= f_cutoff1)= 0;                                                                                                   % Defines the unit step signal to be 0 when the frequency is >= 100                                                                                                                            

r = Y.*unitstep;                                                                                                                    % Creates a variable r, the product of the fourier transform of the DSB-SC signal and the unit step 
                                                                                                                                    % Creates a new figure
subplot(6,2,11)                                                                                                                     % Creates a new subplot
[r_t,t]=inverse_fourier_transform(r,t,ts);                                                                                          % Computes the inverse fourier transform of the signal r
plot(t,real(r_t))                                                                                                                   % Plots the real values of the inverse fourier of the signal r against time
xlabel('time')                                                                                                                      % Labels x axis of the plot
ylabel('M^(t)')                                                                                                                     % Labels y axis of the plot
axis([0 0.15 -2.5 2.5])                                                                                                             % Sets the axis limits shown on the x and y axes
title('Demodulated DSB-SC (AM) modulated signal in the time domain for a cutoff frequency of 100Hz (2.2)')                          % Labels the plot

[r_f,freq_r,df]=fourier_transform(r_t,ts,df);                                                                                       % Computes the fourier transform of r
subplot(6,2,12)                                                                                                                     % Creates a new subplot
plot(freq_r,abs(r_f))                                                                                                               % Plots the absolute value of the fourier transform of r against frequency
xlabel('frequency')                                                                                                                 % Labels x axis of the plot
ylabel('M^(f)')                                                                                                                     % Labels y axis of the plot
axis([-1000 1000 0 0.11])                                                                                                           % Sets the axis limits shown on the x and y axes
title ('Demodulated DSB-SC (AM) modulated signal in the frequency domain for a cutoff frequency of 100Hz(2.2)')                     % Labels the plot
%% Measuring the distortion between the original and recovered message signals (3.1)

f_cutoff2=300;                                                                                                                      % Defines a second cutoff frequency of the ideal lowpass filter at 300Hz
unitstep2=zeros(size(freq_y));                                                                                                      % Produces a unit step signal using the frequencies of the signal y 
unitstep2(freq_y>=-f_cutoff2)=H_max;                                                                                                % Defines the unit step signal to be 1.85 when the frequency is >= -300
unitstep2(freq_y>=f_cutoff2)=0;                                                                                                     % Defines the unit step signal to be 0 when the frequency is >= 300
r2=Y.*unitstep2;                                                                                                                    % Creates a new variable for the product of the fourier transform of the DSB-SC signal and the second unit step 

f_cutoff3=500;                                                                                                                      % Defines a third cutoff frequency of the ideal lowpass filter at 500Hz
unitstep3=zeros(size(freq_y));                                                                                                      % Produces a unit step signal using the frequencies of the signal y
unitstep3(freq_y>=-f_cutoff3)=H_max;                                                                                                % Defines the unit step signal to be 1.85 when the frequency is >= -500
unitstep3(freq_y>=f_cutoff3)=0;                                                                                                     % Defines the unit step signal to be 0 when the frequency is >= 500 
r3=Y.*unitstep3;                                                                                                                    % Creates a new variable for the product of the fourier transform of the DSB-SC signal and the third unit step

[r2_inverse,t]=inverse_fourier_transform(r2,t,ts);                                                                                  % Computes the inverse fourier transform of the signal r2
[r3_inverse,t]=inverse_fourier_transform(r3,t,ts);                                                                                  % Computes the inverse fourier transform of the signal r3
l100=norm(m-r_t);                                                                                                                   % Calculates the magnitude of the difference between the message signal and recovered signal at a cutoff frequency of 100Hz
l300=norm(m-r2_inverse);                                                                                                            % Calculates the magnitude of the difference between the message signal and recovered signal at a cutoff frequency of 300Hz
l500=norm(m-r3_inverse);                                                                                                            % Calculates the magnitude of the difference between the message signal and recovered signal at a cutoff frequency of 500Hz

[maxd1,r_t1,freq_r]=fourier_transform(l100,ts,df);                                                                                  % Computes the fourier transform of the difference between the message signal and recovered signal at a cutoff frequency of 100Hz
[maxd2,r_t2,freq_r]=fourier_transform(l300,ts,df);                                                                                  % Computes the fourier transform of the difference between the message signal and recovered signal at a cutoff frequency of 300Hz
[maxd3,r_t3,freq_r]=fourier_transform(l500,ts,df);                                                                                  % Computes the fourier transform of the difference between the message signal and recovered signal at a cutoff frequency of 500Hz

figure;                                                                                                                             % Creates a new figure
subplot (2,1,1)                                                                                                                     % Creates a new subplot
plot(r_t1,abs(maxd1))                                                                                                               % Plots the absolute value of the distortion at 100Hz against frequency
hold on                                                                                                                             % Retains the next plot in the current axes
plot(r_t2,abs(maxd2))                                                                                                               % Plots the absolute value of the distortion at 300Hz against frequency
hold on                                                                                                                             % Retains the next plot in the current axes
plot(r_t3,abs(maxd3))                                                                                                               % Plots the absolute value of the distortion at 300Hz against frequency
hold off                                                                                                                            % Stops retaining the next plot in the current axes
xlabel('Frequency')                                                                                                                 % Labels x axis of the plot
ylabel('Demodulation distortion')                                                                                                   % Labels y axis of the plot
legend('distortion at 100Hz','distortion at 300Hz','distortion at 500Hz')                                                           % Labels the different lines of the plot
axis([-1000 1000 0 0.006]) 
title('Demodulation distortion of the message signal m(t) at 3 cutoff frequencies (3.1)')                                           % Labels the plot
%% 3.2 Obtaining optimal cutoff frequency

for x=300:5:400                                                                                                                     % Creates a for loop to test a range of cutoff frequencies from 300 to 400Hz
f_cutoff=x;                                                                                                                         % Declares cutoff frequency to be the variable x
unitstep=zeros(size(freq_y));                                                                                                       % Produces a unit step signal using the frequencies of the signal y
unitstep(freq_y>=-f_cutoff)=H_max;                                                                                                  % Defines the unit step signal to be 1.85 when the frequency is >= the cutoff frequency
unitstep(freq_y>=f_cutoff)=0;                                                                                                       % Defines the unit step signal to be 0 when the frequency is >= the cutoff frequency
r=Y.*unitstep;                                                                                                                      % Creates a new variable for the product of the fourier transform of the DSB-SC signal and the unit step
[r_t,t]=inverse_fourier_transform(r,t,ts);                                                                                          % Computes the inverse fourier transform of the signal r
l300=norm(m-r_t);                                                                                                                   % Calculates the magnitude of the difference between the message signal and recovered signal at the cutoff frequency
disp("Distortion at "+ f_cutoff +" = " + l300)                                                                                      % Prints the value of the distortion for a range of different cutoff frequencies
end                                                                                                                                 % Ends the for loop
%% Plotting the optimal cutoff frequency

f_cutoff=330;                                                                                                                       % Defines the optimal cutoff frequency at 330Hz
unitstep=zeros(size(freq_y));                                                                                                       % Produces a unit step signal using the frequencies of the signal y
unitstep(freq_y>=-f_cutoff)=H_max;                                                                                                  % Defines the unit step signal to be 1.85 when the frequency is >= 330Hz
unitstep(freq_y>=f_cutoff)=0;                                                                                                       % Defines the unit step signal to be 0 when the frequency is >= 330Hz
r=Y.*unitstep;                                                                                                                      % Creates a new variable for the product of the fourier transform of the DSB-SC signal and the unit step
[r_t,t]=inverse_fourier_transform(r,t,ts);                                                                                          % Computes the inverse fourier transform of the signal r
l330=norm(m-r_t);                                                                                                                   % Calculates the magnitude of the difference between the message signal and recovered signal at 330Hz
disp("Optimal distortion at 330Hz = " + l330)                                                                                       % Prints the optimal distortion at 330Hz
[r_f,freq_r,df]=fourier_transform(l330,ts,df);                                                                                      % Computes the fourier transform of the difference between the message signal and recovered signal at a cutoff frequency of 330Hz

subplot (2,1,2)                                                                                                                     % Creates a new subplot
plot(freq_r,abs(r_f))                                                                                                               % Plots the absolute value of the distortion at 330Hz against frequency
xlabel('Frequency')                                                                                                                 % Labels x axis of the plot
ylabel('Demodulation distortion')                                                                                                   % Labels y axis of the plot
axis([0 T -0.01 0.01])                                                                                                              % Sets the axis limits shown on the x and y axes
title('Demodulation distortion at the optimal cutoff frequency of 330Hz (3.2)')                                                     % Labels the plot