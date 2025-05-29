clear variables
clc 
%% Parameters given:
Vs = 200;
Power = 7460;
Rs = 0.5;
Rr = 0.43;
Im = 0.03;
Lm = 0.03;
%% Part 1 Choose Frequency
fs = 400;
%% Part 2 Choose Synchronous Speed Ns, and then number of poles
P = 8;
Ns = 120*fs/P;
Nr = Ns;
%% Part 3 Choose Full load slip, then calculate shaft torque Td
slip = 0.025;
wr = 2*pi*Nr/60;
ws = 2*pi*Ns/60;
Td = Power/wr
Ir = sqrt((Td*slip*ws)/(3*Rr));
Xeq = sqrt((Vs^2/Ir^2)-(Rs+(Rr/slip))^2);
%% Part 4 Calculate Stator Current
Xm = Lm*(2*pi*fs);
Im = Vs/Xm;
Ic = 0;
Io = Ic + Im;
Is = Io+Ir
Torquesimulink = Power/ws;
%% Part 5 Calculate Stator and Rotor Inductance, Ls and Lr, in mH
Xs = abs(Xeq/2);
Xr = Xs;
Lr = Xr/(2*pi*fs)
Ls = Xs/(2*pi*fs)

%% Part 6: Plotting Torque Speed and Current Speed Characteristics
figure;
slip=0.0001:0.0001:1;
wr = 2*pi*Nr/60;
ws = 2*pi*Ns/60;
torque = (3.*Vs.^2.*Rr)./(slip.*ws.*((Rs+(Rr./slip).^2)+(Xs+Xr).^2));
Xeq = sqrt(((3.*Vs.^2.*Rr)-(torque.*slip.*ws.*((Rs+(Rr./slip)).^2)))/(torque.*slip.*ws));

plot(slip,torque);
hold on
set(gca,'xdir','reverse');
xlabel("slip");
ylabel("Torque");
title("Torque speed characteristics at 400Hz");

Ir = sqrt((torque.*slip.*ws)./(3.*Rr));

figure;
plot(slip,Ir);
set(gca,'xdir','reverse')
xlabel("slip")
ylabel("Current")
title("Current speed characteristics at 400Hz")
%% Plotting graphs at different frequencies
figure;
plot(slip,torque);
hold on

%% 125%
fs = 400*1.25;
P = 8;
Ns = 120*fs/P;
slip=0.0001:0.0001:1;
ws = 2*pi*Ns/60;
torque = (3.*Vs.^2.*Rr)./(slip.*ws.*((Rs+(Rr./slip).^2)+(Xs+Xr).^2));
plot(slip,torque);

%% 75% Frequency
fs = 400*0.75;
P = 8;
Ns = 120*fs/P;
slip=0.0001:0.0001:1;
ws = 2*pi*Ns/60;
torque = (3.*Vs.^2.*Rr)./(slip.*ws.*((Rs+(Rr./slip).^2)+(Xs+Xr).^2));
plot(slip,torque);

set(gca,'xdir','reverse');
xlabel("slip");
ylabel("Torque");
title("Torque speed characteristics at variable frequency");
legend('torque at 400Hz','torque at 500Hz','torque at 300Hz')

%% Current
%% 100% Frequency
figure;
fs = 400;
Ns = 120*fs/P;
slip=0.0001:0.0001:1;
ws = 2*pi*Ns/60;
torque = (3.*Vs.^2.*Rr)./(slip.*ws.*((Rs+(Rr./slip).^2)+(Xs+Xr).^2));
Ir = sqrt((torque.*slip.*ws)./(3.*Rr));
plot(slip,Ir)
hold on

%% 125%
fs = 400*1.25;
Ns = 120*fs/P;
slip=0.0001:0.0001:1;
ws = 2*pi*Ns/60;
Xeq = sqrt(((3.*Vs.^2.*Rr)-(torque.*slip.*ws.*((Rs+(Rr./slip)).^2)))/(torque.*slip.*ws));
torque = (3.*Vs.^2.*Rr)./(slip.*ws.*((Rs+(Rr./slip).^2)+(Xeq).^2));
Ir = sqrt((torque.*slip.*ws)./(3.*Rr));
plot(slip,Ir);

%% 75%
fs = 400*0.75;
Ns = 120*fs/P;
Nr = Ns;
slip=0.0001:0.0001:1;
wr = 2*pi*Nr/60;
ws = 2*pi*Ns/60;
Xeq = sqrt(((3.*Vs.^2.*Rr)-(torque.*slip.*ws.*((Rs+(Rr./slip)).^2)))/(torque.*slip.*ws));
torque = (3.*Vs.^2.*Rr)./(slip.*ws.*((Rs+(Rr./slip).^2)+(Xeq).^2));
Ir = sqrt((torque.*slip.*ws)./(3.*Rr));

plot(slip,Ir);

set(gca,'xdir','reverse')
xlabel("slip")
ylabel("Current")
title("Current speed characteristics")
legend('current at 400Hz','current at 500Hz','current at 300Hz')