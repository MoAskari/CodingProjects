close all
clear
clc

%% Input Parameters

Speed = 7; % Speed in m/s

% Speed Conversion - 1.0 mph = 0.447 m/s
%                  - 1.0 km/h = 0.278 m/s
% Display the vehicle speed in mph and km/h
disp(' ')
disp(['Speed in mph = ', num2str(Speed/0.447), 'mph'])
disp(['Speed in km/h = ', num2str(Speed/0.278), 'km/h'])
%% Define the suspension system parameters

Wn = 12; % natural frequency of suspension system
Zeta = 0.45; % damping factor of suspension system

sys_Suspension = tf(Wn^2, [1 2*Zeta*Wn Wn^2]); % transfer function

% plot of the system step response
figure(1)
step(sys_Suspension)
grid
title('Step response of the Suspension System')

%plot the bode plot of the system

figure(2)
bode(sys_Suspension)
grid
title('Bode Plot of the Suspension System')
%% Define road profile of the speed bump, interms of displacement

% Define distance for face length and top length
BumpFace = 0.5;
BumpTop = 1;

% Horizontal points
x0 = 0;
x1 = BumpFace;
x2 = BumpFace + BumpTop;
x3 = BumpFace + BumpTop + BumpFace;

% height points
h0 = 0;
h1 = 101;
h2 = 101;
h3 = 0;

% define array of geometry
% Horizontal distance
X = [x0, x1, x2, x3];
% road/wheel vertical displacement profile
H = [h0, h1, h2, h3];

% plot the geometry
figure(3)
plot(X,H,'r-x');
grid
title('Road Bump Profile')
xlabel('Road Distance (m)')
ylabel('Height (mm)')
ylim([-10 110])

%% Define the system input signal, interms of an evenly spaced time array
% and the vertical displacement of the wheel, indexed to the time array

% Define the time for start of bump and end of simulation, 0.25 seconds
% lead-in with the simulation running for 20 seconds after the wheel hits
% the front edge of the speed bump
BumpTime = 0.25;
EndTime = BumpTime + 20;

% Calculate a set of time points to be interpolated for the simulation, to
% align with a modified H array, imcorporating the BumpTime and EndTime
% parameters
Time_Lumped = [0,(X ./ Speed) + BumpTime, EndTime];

% Define an evenly sampled time array, between 0 and EndTime, for the lsim
% simulation
Time = linspace(0, EndTime, 2^16);

% Interpolate the a modified H array to align with the Time array
H_Fine = interp1(Time_Lumped,[0,H,0], Time, 'linear');


%% Simulation of the suspension system response

% Simulate the vehicle displacement using the suspension system transfer
% function and the evenly sampled time and displacement arrays
Response_H = lsim(sys_Suspension, H_Fine, Time)';

% Plot the time domain displacement profiles for both the wheel and the vehicle
figure(4)
plot(Time, H_Fine, Time, Response_H)
grid
legend('Wheel - Input Signal', 'Vehicle Body - Output Signal')
title(['Time Domain System Responses (' num2str(Speed) 'm/s)'])
xlabel('Time (s)')
ylabel('Vertical Displacement (mm)')
xlim([0 Time_Lumped(5) + 1.5])
%% Calculate the frequency responses of the system

% Calculate the frequency bins for the fft
Freq = ((1/diff(Time(1:2)))/length(Time))*(0:length(Time)-1);
FreqResp = squeeze(freqresp(sys_Suspension,Freq,'Hz'))';

% x-axis frequency plot display limit, Hz
FreqLim = 25;

figure(5)
subplot(3,1,1)

% plot the frequency response of the suspension system
plot(Freq,abs(FreqResp))
grid
xlim([0 FreqLim])
title('Frequency Response of the Suspension System')
ylabel('Gain')

subplot(3,1,2)

% plot the frequency magnitudes for the input signal
plot(Freq, abs(fft(H_Fine)))
grid
xlim([0 FreqLim])
ylabel('Amplitude')
title('Frequency Components of the Input Signal')

subplot(3,1,3)

% plot the frequency magnitudes for the output signal
plot(Freq, abs(fft(Response_H)))
grid
xlim([0 FreqLim])
title('Frequency Components of the Output Signal')
xlabel('Frequency (Hz)')
ylabel('Amplitude')



