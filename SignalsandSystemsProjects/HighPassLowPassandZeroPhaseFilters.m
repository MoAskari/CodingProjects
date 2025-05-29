clc;
clear;
Fs=1000;
Rp=0.2;
Fc=[180,220];%bandwidth at the -3dB points
[numd,dend]=cheby1(4,Rp,2*Fc/Fs); %BPF: wc=[w1,w2], 0<w1, w2<1
% f=4*():500); don't need to put this
[H,f]=freqz(numd,dend,512,1000);
mag=20*log10(abs(H));
figure;
plot(f,mag,'LineWidth',2); grid
xlim([100 300]);
xlabel('Frequency, (Hz)')
ylabel ('Magnitude response, (dB)')
title('Frequency response of the Chebyshev Type I bandpass filter')
sys = tf(numd,dend,1/Fs);
figure;
pzmap(sys);
%high pass and low pass are cascaded for bandpass and bandstop
%so doubled the order

%% p2
clear;
clc;
t = (1:350);%time base
o=ones(1,50); %an array of 1's
z=zeros(1,50); %an array of 0's
x=[z o z o z o z]; %signal with three pulses
cutoff=0.25; %cutoff frequency of filter
[num,den]=butter(1,cutoff,'high');
omega=-pi:pi/150:pi;
H = freqz(num,den,omega);
Mag = abs(H);
Phase = angle(H);
figure
subplot(2,1,1)
plot(omega,Mag);
title('filter');
xlabel('omega(rad/s)');
ylabel('Mag');
subplot(2,1,2)
plot(omega,Phase);
xlabel('omega(rad/s)');
ylabel('Phase');
y=filter(num,den,x); %filtered output
figure
subplot (2,1,1)
plot(t,x);
title('original signal');
xlabel('time (sampling points)');
ylabel('amplitude');
subplot(2,1,2)
plot(t,y);
title('filtered signal');
xlabel('time (sampling points)');
ylabel('amplitude');
%high pass filter, high frequency passed but attenuated due to the long
%transition. no, small or slow change in time domain is low freq part;
% big or quick change in time domain is high freq part. The filters are not
% zero phase so the value of the filtered signal has negative value.
%% p3
clc;
clear;
Fs=2000; %specify sampling rate
Fn=Fs/2; %specify Nyquist frequency
Wp=200/Fn; %normalised passband frequency
Ws=250/Fn;%normalized stopband frequency
Rp=1; Rs=40; %passband and stopband attenuation
[N1, Wc1]=buttord(Wp,Ws, Rp,Rs); %butterworth filter
[N2, Wc2]=cheb1ord(Wp,Ws, Rp,Rs); %Chebyshev Type 1 filter
[N3, Wc3]=cheb2ord(Wp,Ws, Rp,Rs); %Chebyshev Type 2 filter
[N4, Wc4]=ellipord(Wp,Ws, Rp,Rs); %Elliptic filter
%% p4
clc;
clear;
load('ecg(1).mat');
fs=500;
t=(0:1:(length(ecg)-1))/fs;
ecg=ecg/500;
figure
plot(t,ecg);
title('ECG');
xlabel('t(s)');
ylabel('volts');

N = 4500;
Ecg = fftshift(fft(ecg,N));
F = fs*(-N/2:N/2-1)/N;
figure
plot(F,abs(Ecg))
title('signal ecg');
xlabel('Frequency');
ylabel('Magnitude');

wo = 50/(500/2); bw = wo/35;
[b,a] = iirnotch(wo,bw);
fvtool(b,a);
ecg2=filter(b,a,ecg);
figure
plot(t,ecg2);
title('ECG2');
xlabel('t(s)');
ylabel('volts');

N=4500;
Ecg2 = fftshift(fft(ecg2,N));
F = fs*(-N/2:N/2-1)/N;
figure
plot(F,abs(Ecg2));
title('filtered signal ecg2');
xlabel('frequency');
ylabel('magnitude');
Wp = 0.1/(fs/2);
Ws = 0.3/(fs/2);
Rp=0.5;
Rs=40;
[n,Wc]=ellipord(Wp,Ws,Rp,Rs);
% [num,den]=butter(5,0.25/(Fs/2),'high'); %HPF;0<wc<1
[num,den]=ellip(n,Rp,Rs,Wc,'high'); %HPF; 0<wc<1
ecg3=filtfilt(num,den,ecg2);
figure
plot(t,ecg2);
hold on
plot(t,ecg3);
title('ECG(one period)');
legend('ecg2','ecg3')
xlabel('t(s)');
ylabel('volts');
fvtool(num,den);

N = 4500;
Ecg3 = fftshift(fft(ecg3,N));
F = fs*(-N/2:N/2-1)/N;
figure
plot(F,abs(Ecg3))
title('filtered signal ecg3');
xlabel('frequency');
ylabel('magnitude');
%% p5
clc;
clear;
% Zero-phase filter a noist ECG waveform using an IIR filter.
x = ecg(500)'+0.1*randn(500,1); %noisy waveform
[b,a] = butter(12,0.2,'low'); % IIR filter design n wc lowpass
y = filtfilt(b,a,x); % zero-phase filtering
y2 = filter(b,a,x); % conventional filtering
plot(x,'k-.'); grid on; hold on
plot([y y2],'LineWidth',1.5);
legend('Noisy ECG','Zero-phase Fitlering','Conventional Filtering');
