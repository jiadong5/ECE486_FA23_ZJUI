# Homework 1

## Question 1

![image-20231006164826474](C:\Users\Jiadong Hong\AppData\Roaming\Typora\typora-user-images\image-20231006164826474.png)

### (a)

$$
3\ddot{x} = f(t)-2x-7\dot{x}
$$

### (b)

$$
\left\{\begin{matrix}
\dot{x_1} = x_2 
\\
\dot{x_2} = \frac{1}{3}(-7x_2-2x_1+f(t))
\end{matrix}\right.
\\
\dot{\mathbf{x}} = \begin{bmatrix}
0  & 0\\
-\frac{2}{3}  & -\frac{7}{3}
\end{bmatrix} \cdot \begin{bmatrix}
x_1 \\
x_2
\end{bmatrix}+\begin{bmatrix}
0 \\
\frac{1}{3}
\end{bmatrix}f(t)
\\
\mathbf{x}=\begin{bmatrix}
x_1\\
x_2
\end{bmatrix}
$$

### (c)

$$
3s^2X(s) + 7sX(s) + 2X(s) = F(s) + 3sx(0) + 3\dot{x}(0) + 7x(0)
$$

### (d)

$$
3s^2X(s) + 7sX(s) + 2X(s) = 50\left(\frac{1}{s^2 + 1}\right) + 3sx(0) + 3\dot{x}(0) + 7x(0)
\\
\Rightarrow X(s) = \frac{\frac{50}{s^2 + 1} - 3s - 10}{3s^2 + 7s + 2} \\
\Rightarrow x(t) = -\frac{6 e^{-2t}}{5} + \frac{36 e^{-\frac{t}{3}}}{5} - \sin(t) - 7 \cos(t)
$$

## Question 2

![image-20231007011816547](C:\Users\Jiadong Hong\AppData\Roaming\Typora\typora-user-images\image-20231007011816547.png)

### (a)

$$
x(t) = 2\cos(\frac{t}{2})
$$

### (b)

FVT has certain limitations and prerequisites for its applicability:

1. **Stability**: The system must be stable, meaning that all of its poles (complex numbers representing system dynamics) should have negative real parts.
2. **Bounded Input**: The input signal to the system should be bounded, meaning it should not have infinite amplitude.
3. **Convergent Laplace Transform**: The Laplace transform of the system's output, denoted as X(s), must converge for s→0.

In the case of 
$$
X(s) = \frac{8s}{4s^2+1}
$$
the system has complex poles (roots of the denominator) located in the complex plane, which violates the stability condition since it has poles with positive real parts. Therefore, FVT does not apply here.