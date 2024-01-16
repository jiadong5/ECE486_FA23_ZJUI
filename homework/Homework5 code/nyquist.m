% nyquist plot
s = tf("s");
G = 1/((s+1) * (s^2+s+1));
% G = 1/(s-1);
% nyquist(G);
k = 3/2;
H = k*G/(1+k*G);
nyquist(H);
  
