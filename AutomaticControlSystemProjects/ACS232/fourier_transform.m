function [M,freqs,df_o]=fourier_transform(m,ts,df_i) 

%       [M,freqs,df]=fourier_transform(m,ts,df) returns the Fourier
%       transform of the discrete-time signal m.
%       INPUT:
%           m:  the discrete-time signal
%           ts: the time interval 
%           df_i: the desired frequency interval of the Fourier transform
%       OUTPUT:
%           M:      the Fourier transform of the signal m
%           freqs:  the frequencies for which the Fourier transform is evaluated in M 
%           df:     the frequency interval used for the Fourier transform.
%           Please note that df_o=<df_i since df_o is chosen to optimize
%           the Fourier transform computation.

fs=1/ts;
if nargin == 2
  n1=0;
else
  n1=fs/df_i;
end
n2=length(m);
n=2^(max(nextpow2(n1),nextpow2(n2)));
M=fft(m,n);
m=[m,zeros(1,n-n2)];
df_o=fs/n;

%scaling and shifting
M=fftshift(M)/fs;
freqs=[0:df_o:df_o*(length(m)-1)]-fs/2;