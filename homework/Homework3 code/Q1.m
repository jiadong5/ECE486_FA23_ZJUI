% 定义传递函数
numerator = [1,0];                 % 分子的系数
denominator = [1,2,0,-2,-1];  % 将两个因子相乘得到分母系数

% 创建传递函数模型
sys = tf(numerator, denominator);

% 画出根轨迹图
rlocus(sys);

% 添加图表标签
title('Root Locus Plot');  % 图表标题
xlabel('Real Axis');       % x轴标签
ylabel('Imaginary Axis');  % y轴标签
grid on;                   % 显示网格