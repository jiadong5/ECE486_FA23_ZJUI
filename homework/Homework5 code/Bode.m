% bode plot
s = tf("s");
G = 1/((s+1) * (s^2+s+1));
bode(G);
