%ACS1321 Exam Resit MATLAB Code

%% LECTURE 1 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% DEFINE CLOSED LOOP TRANSFER FUNCTION AND TAKE STEP RESPONSE

s = tf ('s'); % define the Laplace variable as a transfer function
G = -3/(2*s+1) ; % Use s to write down the transfer function directly
step(G)

%% PLOT OF UNIT STEP RESPONSE WITH STEP INFO

s = tf('s'); % define the Laplace variable s as a transfer function
G = 1/(1.4*s^2 + s + 1.9) % use s to write down the transfer function directly
step(G) % obtain plot of step response
[y,t] = step(G); % obtain numerical values of step response y, for time t
stepinfo(G) % transient step response analysis of transfer function G 

%% PLOT OF IMPULSE RESPONSE

s = tf('s'); % define the Laplace variable s as a transfer function
G = 10/(s+2); % use s to write down the transfer function directly
impulse(G); % plot impulse response from transfer function G
[y,t] = impulse(G); % obtain numerical values of impulse response y for time

%% SYMBOLIC/ANALYTIC EXPRESSION OF STEP RESPONSE USING INVERSE LAPLACE (SO IN THE FORM: y(t) = K-Ke^(-t/T))

syms s % define the Laplace variable s as a symbolic variable
G = 2.47*(s+1)/(s^2+3*s+5); % define the plant transfer function symbolically
R = 1/s; % define the unit step input symbolically
Y = G*R; % define the output as output=plant*step input
y = ilaplace(Y) % obtain the analytic form of the step response

%% OBTAIN TRANSFER FUNCTION POLES

s = tf('s'); % define the Laplace variable s as a transfer function
G = 5/(7*s+5); % use s to write down the transfer function directly
pole(G) % obtain numerical values of poles
pzmap(G) % obtain plot of pole-zero map in the complex plane

%% RESIDUE (FOR FINDING THE PARTIAL FRACTION EXPANSION OF A TRANSFER FUNCTION)

b = [9.2 (9.2*3) (9.2*2)]
a = [1 22 175 594 720 0]
[r,p,k] = residue(b,a)
doc residue





%% LECTURE 2 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

omegan = sqrt(13.5)
zeta = ((1)/(2*omegan))
omegad = omegan*(sqrt(1-(zeta)^2))
%% DEFINE A CLOSED LOOP UNITY NEGATIVE FEEDBACK SYSTEM WITH CONTROLLER C AND PLANT G (IN 2 WAYS) - SECOND METHOD IS BETTER, TO SEE WHAT'S GOING ON. 

% METHOD 1
% s = tf('s'); % define the Laplace variable s 
% G = 10/(s+2); % plant transfer function 
% C = 3; % proportional controller TF with gain=3
% T = feedback(C*G,1); % closed loop transfer function

% METHOD 2
s = tf('s'); % define the Laplace variable s 
G = 1/(s^2+1.4*s+18.1); % use s to write down the plant transfer function 
C = 1.1; % proportional controller TF with gain=3
T = minreal((C*G)/(1+C*G)) % closed loop transfer function

% THEN ANALYSE IT
subplot (1, 2, 1); step(T) % obtain plot of step response
[y,t] = step(T); % obtain numerical values of step response
subplot (1, 2, 2); pzmap(T)
p = pole(T) % obtain poles of closed loop system







%% LECTURE 3 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% OBTAIN TRANSFER FUNCTION POLES, STEP AND IMPULSE RESPONSE (AS IN LECTURE 1)

s = tf('s'); % define the Laplace variable s as a transfer function
G = (3)/(2*s^2+4*s+2); % use s to write down the transfer function directly
[y,t] = impulse(G); % obtain numerical values of impulse response y for time
pole(G) % obtain numerical values of poles
subplot (1, 3, 1); impulse(G); % plot impulse response from transfer function G
subplot (1, 3, 2); step(G); % plot step response from transfer function G
subplot (1, 3, 3); pzmap(G) % obtain plot of pole-zero map in the complex plane







%% LECTURE 4 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ANALYSE TRANSIENT RESPONSE OF SECOND ORDER SYSTEM TRANSFER FUNCTION USING STEPINFO

s = tf('s'); % define the Laplace variable s as a transfer function
G = 25/(20*s^2+20*s+100); % use s to write down the transfer function directly
step(G) % obtain plot of step response
[y,t] = step(G); % obtain numerical values of step response y, for time t
stepinfo(G) % transient step response analysis of transfer function G 

%% OBTAIN CLOSED LOOP STEP RESPONSE TO A UNIT STEP, NUMERICAL POLES, POLE MAP AND TRANSIENT RESPONSE FOR A SECOND ORDER SYSTEM

s = tf('s'); % define the Laplace variable s as a transfer function
G = 1/(s^2+3*s+2); % use s to write down the transfer function directly
[y,t] = step(G); % obtain numerical values of step response y, for time t
stepinfo(G) % transient step response analysis of transfer function G 
pole(G) % obtain numerical values of poles
subplot (1, 2, 1); step(G); % plot step response from transfer function G
subplot (1, 2, 2); pzmap(G) % obtain plot of pole-zero map in the complex plane

%% FIND A CONTROLLER GAIN K THAT STABILISES A CLOSED LOOP TRANSFER FUNCTION BY CHECKING POLES AND STEP RESPONSE (SAME AS IN LECTURE 2, JUST USE TRIAL AND ERROR FOR VALUES OF K)

s = tf('s'); % define the Laplace variable s 
G = 1/(s^2+3*s-2); % use s to write down the plant transfer function 
K = 2.1;
C = K; % proportional controller TF with gain=3
T = minreal((C*G)/(1+C*G)); % closed loop transfer function

subplot (1, 2, 1); step(T) % obtain plot of step response
[y,t] = step(T); % obtain numerical values of step response
subplot (1, 2, 2); pzmap(T)
p = pole(T) % obtain poles of closed loop system







%% LECTURE 5 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%  PLOT STEP RESPONSE FOR CLOSED LOOP TRANSFER FUNCTION AND CHECK THAT THE STEADY STATE ERROR IS SIMILAR TO THAT CALCUlATED THROUGH FINAL VALUE THEOREM INSPECTION OF 1/1+CG

% obtain step response of closed loop system and final error
s = tf ('s'); % Laplace variable
C = 1.2; % control transfer function
G = 1/(1.4*s^2 + 4.6*s + 1.6) ; % plant transfer function
T = minreal (( C*G ) /(1+ C* G)) ; % closed loop transfer function
figure ; step (T) % plot closed loop step response
y = step (T) ; % write step response into y
sse = 1- y(end ) % steady state error ( sse ) e=r-y

%% PLOT THE TRANSFER FUNCTION FROM REFERENCE INPUT R(S) TO ERROR E(S) AND CHECK THAT THE STEADY STATE ERROR IS EQUAL TO WHAT WAS CALCULATED THROUGH FVT WITH 1/1+CG
% steady - state error analysis of closed loop system
E = minreal (1/(1+ C *G) ); % error transfer function
figure ; step (E) % plot step response of error
e = step (E) ; % write error step response into e
final_e = e( end ) % final step error value

%% ANALYSE PROPORTIONAL CONTROL SYSTEM FOR STABILITY (THROUGH POLES) STEP RESPONSE, TRANSIENT RESPONSE AND STEP RESPONSE OF REFERENCE TO ERROR
s = tf ('s'); % Laplace variable
C = 10; % control transfer function
G = 2/(8* s ^2+3* s +2) ; % plant transfer function
T = minreal (( C*G ) /(1+ C* G)) ; % closed loop transfer function
pole (T) % calculate poles
subplot (1, 3, 1); pzmap(T) % obtain plot of step response
subplot (1, 3, 2); step (T)
stepinfo (T )
E = minreal (1/(1+ C *G) ); % error transfer function
subplot (1, 3, 3); step (E) % step response of error







%% LECTURE 6 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% PROPORTIONAL INTEGRAL DERIVATIVE CONTROLLER TRANSFER FUNCTION WITH GAINS Kp, Ki and Kd (remove either of these terms where necessary).

s = tf('s'); % Laplace variable defined as transfer function 
G = 1/(1.9*s^2 + 2.3*s + 3.1); % first order plant transfer function

% define PID controller 
Kp = 0.3; % proportional gain 
Ki = 1; % integral gain
Kd = 0; % derivative gain
C = Kp + Ki/s + Kd*s; % PID controller transfer function

% PID closed loop system
T = minreal((C*G)/(1+C*G)); % PID closed loop control system TF
step(T)

%% COMPARING PROPORTIONAL AND PI STEP RESPONSES
clear all; 

% define a first order plant
s = tf('s'); % Laplace variable define as transfer function 
G = 1/(s+1); % first order plant transfer function

% define the proportional control system
Kp = 10; % proportional control gain
C = Kp; % controller transfer function
Tp = minreal((C*G)/(1+C*G)); % proportional closed loop control system TF

% define PI control system
Kp = 10; % proportional control gain 
Ki = 100; % integral gain
C = Kp+Ki/s; % PI controller transfer function
Tpi = minreal((C*G)/(1+C*G)); % PI closed loop control system TF

% closed loop step responses 
nt = 1.2; % time length of step response (seconds)
[yp,tp] = step(Tp,nt); % step response of the proportional control system
[ypi,tpi] = step(Tpi,nt); % step response of the PI control system

% plot closed loop step responses 
figure; % new figure
hold on; % hold onto multiple plots 
plot(tp,yp,'r','linewidth',2); % plot proportional control step
plot(tpi,ypi,'g','linewidth',2); % plot PI control step
plot([-0.1 0 0 nt],[0 0 1 1],'k--',... % dots indicate line break
 'linewidth',2); % plot reference step input 
xlim([-0.1 nt]); % x-axis limits
ylim([-0.1 1.3]); % y-axis limits
xlabel('Time (s)'); % x-axis label 
ylabel('Output'); % y-axis label

%%  COMPARING PROPORTIONAL, PI AND PID CONTROL THROUGH STEP RESPONSE AND POLES

s = tf ('s'); % Laplace variable
G = 1/( s ^2 + 6* s + 3) ; % plant transfer function

% define the proportional control system
Kp = 1; % proportional control gain
C = Kp ; % prop . control transfer function
Tp = minreal (( C* G) /(1+ C* G) ); % prop . closed loop TF

% define PI control system
Kp = 1; % proportional control gain
Ki = 0.1; % integral gain
C = Kp + Ki /s ; % PI controller transfer function
Tpi = minreal (( C*G ) /(1+ C* G)) ; % PI closed loop TF

% define PID control system
Kp = 1; % proportional control gain
Ki = 0.1; % integral gain
Kd = 10; % derivative gain
C = Kp + Ki /s + Kd* s; % PI controller transfer function
Tpid = minreal (( C*G ) /(1+ C* G)) ; % PI closed loop TF

% closed loop step responses
subplot (1 ,2 ,1)
step ( Tp,'r'); hold on % step response for proportional control
step ( Tpi,'g' ) ; % step response for PI control system
step ( Tpid ,'b') ; % step response for PI control system
legend (' Proportional Control ','PI Control ','PID Control') % insert legend

% closed loop plot of poles
subplot (1 ,2 ,2)
pzmap ( Tp ); hold on % step response for proportional control
pzmap ( Tpi ) ; % step response for PI control
pzmap ( Tpid ) ; % step response for PI control
legend (' Proportional Control ','PI Control ','PID Control') % insert legend

%% DESIGNING A FEEDBACK PI CONTROLLER THAT IS STABLE, GIVES 0 STEADY STATE ERROR AND HAS LESS THAN 20% OVERSHOOT.
% MAKE SURE TO USE SISOTOOL - TUNING METHODS - PID TUNING AND MESS AROUND WITH THE TWO BOTTOM SLIDERS UNTIL YOU GET SOMEWHERE.

s = tf ('s'); % Laplace variable
G = (s^2+3*s+2)/[s^4+5*s^3+2*s^2+1] ; % plant transfer function
Kp =1; % proportional control gain
Ki = 0; % integral control gain
C = Kp + Ki /s ; % controller transfer function
T = minreal (( C*G ) /(1+ C* G)) ; % closed loop transfer function
figure ; step (T) % closed loop step response
stepinfo (T ) % transient performance
% also try sisotool - go to Tuning Methods -> PID Tuning
sisotool (G )

%% USING A FOR LOOP TO TRIAL AND ERROR DIFFERENT VALUES OF GAIN FOR A PID CONTROLLER (SISOTOOL MIGHT ALSO HELP HERE)
clear all; 
% define a first order plant
s = tf('s'); % Laplace variable define as transfer function 
G = 0.2/(s+0.1); % first order plant transfer function
figure;
for i = 0.1:0.1:1
    % define PI control system
    Kp = i; % proportional control gain
    Ki = 0;
    Kd = 0;
    C = Kp+Ki/s+Kd*s; % PI controller transfer function
    Tpid = minreal((C*G)/(1+C*G)); % PI closed loop control system TF
    step(Tpid);
    hold on; % hold onto multiple plots
    legend ('1','2','3','4','5')
end







%% LECTURE 7 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% EVALUATE GAIN AND PHASE AT A SINGLE FREQUENCY FOR A SYSTEM

w = 2; % frequency in rad /s
G = 4.3/(1*(j*w)+1.7) ; % freq . response function
magG = sqrt ( real (G ) ^2 + imag (G ) ^2) % magnitude
phaseG = atan2 ( imag ( G) , real ( G) ) % phase in radians
phaseGdeg = phaseG /(2* pi ) * 360 % phase in degrees

%% ALTERNATIVE SOLUTION USING THE BODE FUNCTION
s = tf ('s'); % Laplace variable
w = 2;
G = 6.8/(s+5.8) ; % define transfer function
[ mag , phase ] = bode (G , w) % obtain gain and phase in degrees.

%% EVALUATE GAIN AND PHASE OVER A RANGE OF FREQUENCIES

w = 0.001:0.1:100; % define frequencies
for i = 1:length(w)
 G = 1/(j*w(i) + 1); % frequency response function
 magG(i) = sqrt(real(G)^2 + imag(G)^2); % gain
 phaseG(i) = atan2(imag(G),real(G)); % phase
end
% plot gain and phase
figure; % new figure
subplot(2,1,1); % subplot 1
semilogx(w,magG) % gain plotted on log x-axis
xlabel('Frequency (rad/s)') % x-axis label
ylabel('Gain') % y-axis label
subplot(2,1,2); % subplot 2
semilogx(w,(phaseG./(2*pi))*360) % phase plotted on log x-axis
xlabel('Frequency (rad/s)') % x-axis label
ylabel('Phase (deg)') % y-axis label

%% MAKE A BODE PLOT TO FIND GAIN AND PHASE (MAGNITUDE IN DECIBELS AND ABSOLUTE UNITS)

s = tf('s'); % define Laplace variable as transfer function
C = 50
G = 0.08/(s+2); % define transfer function
T = minreal((C*G)/(1+C*G));
% magnitude and phase for frequencies w rad/s of transfer function G
[mag,phase,w] = bode(T);
figure; % new figure
bode(T); % plot gain and phase (freq in rad/s and gain in dB) 
figure; % new figure
h = bodeplot(T); % Bode plot with handle h
setoptions(h,'FreqUnits','Hz','MagUnits','abs'); % freq. in Hz, gain in abs.







%% LECTURE 8 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% PLOT GAIN, PHASE AND STEP RESPONSE OF A CLOSED LOOP SYSTEM, EITHER P, PI OR PID. 

s = tf ('s'); % Laplace variable
G = 4.3/(s+1.7) ; % plant transfer function
Kp = 1; % proportional control gain
Ki = 0; % integral control gain
Kd = 0; % derivative control gain
C = Kp + Ki /s + Kd*s; % controller transfer function
T = minreal (( C*G ) /(1+ C* G)) ; % closed loop transfer function
% magnitude and phase for frequencies w rad/s of transfer function G
[mag,phase,w] = bode(G);
figure; % new figure
bode(T); % plot gain and phase (freq in rad/s and gain in dB)
figure;
h = bodeplot(T); % Bode plot with handle h
setoptions(h,'FreqUnits','Hz','MagUnits','abs'); % freq. in Hz, gain in abs.
figure;
step(T)







%% LECTURE 9 AND 10 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% PLOTTING STEP RESPONSE AND FREQUENCY RESPONSE OF CLOSED LOOP TRANSFER FUNCTION AND SENSITIVITY FUNCTION

% Sensitivity frequency response example
clear all

% define plant transfer function and controller
s = tf('s'); % Laplace variable 
G = 0.08/(s+2); % plant
Kp = 1; % proportional gain
Ki = 50; % integral gain
C = Kp + Ki/s; % PID controller

% closed loop and sensitivity transfer functions
T = minreal((C*G)/(1+C*G)); % closed loop transfer function
S = minreal(1/(1+C*G)); % sensitivity function
RU = minreal(C/(1+C*G)); % reference to input TF
VU = minreal(-C/(1+C*G)); % disturbance to input TF

% step responses 
maxT = 10; % time length of step in seconds
[y1,t] = step(T,maxT); % step response of closed loop system
u1 = step(RU,t); % step response from reference to input
y2 = step(S,t); % step of sensitivity function
u2 = step(VU,t); % step of disturbance to input
N = length(t); % number of samples in step response

% frequency response
w = logspace(-1,1,100); % frequencies in rad/s
[mag1,phase1] = bode(T,w); % magnitude and phase of closed loop TF
[mag2,phase2] = bode(S,w); % magnitude and phase of sensitivity TF
f = w/(2*pi); % frequencies in Hz for plotting

% setup new figure
figure;

% plot step response of closed loop system
subplot(2,2,1)
plot(t,y1,'k','linewidth',1); hold on % plot step response
plot(t,ones(N,1),'k--','linewidth',1); % plot desired response
xlim([0 maxT]); % define x-axis limits
ylim([-0.1 1.1]); % define y-axis limits
title('(a) Closed Loop Step Response'); % define title
xlabel('Time (s)'); ylabel('Output y(t)'); % define x and y labels

% plot step response of sensitivity function
subplot(2,2,3)
plot(t,y2,'k','linewidth',1); hold on
plot(t,zeros(N,1),'k--','linewidth',1); 
xlim([0 maxT])
ylim([-0.1 1.1])
title('(b) Sensitivity Function Step Response')
xlabel('Time (s)'); ylabel('Output y(t)');

% plot freq response of closed loop system
subplot(2,2,2)
semilogx(f,squeeze(mag1),'k','linewidth',1); hold on
semilogx([f(1) f(end)],[1 1],'k--','linewidth',1)
xlim([f(1) f(end)]);
title('(c) Closed Loop Gain')
xlabel('Frequency (Hz)'); ylabel('Gain |T(j\omega)|'); grid

% plot freq response of sensitivity function
subplot(2,2,4)
semilogx(f,squeeze(mag2),'k','linewidth',1); hold on
semilogx([f(1) f(end)],[1 1],'k--','linewidth',1)
xlim([f(1) f(end)]);
title('(d) Sensitivity Function Gain')
xlabel('Frequency (Hz)'); ylabel('Gain |S(j\omega)|'); grid

%% PLOT SENSITIVITY FUNCTION STEP AND FREQUENCY RESPONSE FOR A PID CONTROLLER

% define sensitivity function
s = tf ('s'); % Laplace variable
C = 0.25 + 2.5/ s + 0.005* s ; % PID controller
G = 3/( s ^2+2* s +10) ; % plant transfer function
S = minreal (1/(1+ C *G) ); % sensitivity function
% plot Bode diagram and step response
figure ; % new figure
h = bodeplot ( S); % closed loop Bode plot
setoptions (h , 'FreqUnits','Hz','MagUnits','abs'); % change units
grid on % turn on grid

%% ANALYSING A TRANSFER FUNCTION ALL THE WAY THROUGH: FROM DIFFERENTIAL EQUATION TO FINDING STABILITY, TRANSIENT RESPONSE, STEADY STATE RESPONSE, BODE DIAGRAM AND CHECKING SENSITIVITY FUNCTION BODE PLOT FOR DISTURBANCE REJECTION

% define transfer functions
s = tf ('s'); % Laplace variable
G = 0.08/(s+2) ; % plant transfer function
C = 30+60/s; % PI controller
T = minreal (( C*G ) /(1+ C* G)) ; % closed loop transfer function
S = minreal (1/(1+ C *G) ); % sensitivity function
% plot step responses and poles of closed loop transfer function
subplot (2 ,3 ,1)
step (T)
subplot (2 ,3 ,4)
pzmap (T)
% plot bode diagram of closed loop transfer function
subplot (2 ,3 ,[2 5])
h = bodeplot ( T);
setoptions (h , 'FreqUnits','Hz','MagUnits','abs');
grid on
title ('Reference tracking ')
% plot bode diagram of sensitivity function
subplot (2 ,3 ,[3 6])
h = bodeplot ( S);
setoptions (h , 'FreqUnits','Hz','MagUnits','abs');
grid on
title (' Sensitivity to disturbances ')
% obtain transient response info
stepinfo (T)
