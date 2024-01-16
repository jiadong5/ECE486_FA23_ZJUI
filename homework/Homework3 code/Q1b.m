% 定义传递函数
numerator = [1,0];                 % 分子的系数
denominator = conv([1,1], [1,3,3,1]);  % 将两个因子相乘得到分母系数
% 创建传递函数模型
sys = tf(numerator, denominator);

% 计算开环传递函数在增益为1时的相位和频率
[~, ~, ~, frequency] = margin(sys);

% 计算相位在频率为 j 时的值
phase_j = interp1(frequency, sysresp(sys, 1i), 1i, 'pchip');

% 判断相位是否满足条件
if mod(phase_j, 180) == 0
    disp('Point s = j is on the root locus.');
else
    disp('Point s = j is not on the root locus.');
end