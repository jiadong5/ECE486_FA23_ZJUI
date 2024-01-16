% 创建一张图
figure;

% 绘制六条曲线，每条曲线使用不同的颜色和线条样式
plot(tout1,  y1, 'b-', 'LineWidth', 2);
hold on;
plot(tout3a, y3a, 'r--', 'LineWidth', 2);
plot(tout3b, y3b, 'g-.', 'LineWidth', 2);
plot(tout3c, y3c, 'm:', 'LineWidth', 2);
plot(tout3d, y3d, 'c-', 'LineWidth', 2);

% 添加图例，指定每条曲线的标签
legend('y1', 'y3a', 'y3b', 'y3c', 'y3d');

% 添加标题和轴标签
title(['Plot of Five Curves']);
xlabel('Time');
ylabel('Value');

% 设置 x 轴范围为 0 到 3
xlim([0, 3]);
ylim([-1,2]);

% 停止图形保持
hold off;