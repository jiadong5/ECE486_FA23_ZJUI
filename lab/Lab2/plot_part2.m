% 创建一张图
figure;

% 绘制六条曲线，每条曲线使用不同的颜色和线条样式
plot(tout1, y1, 'b-', 'LineWidth', 2);
hold on;
plot(tout2a, y2a, 'r--', 'LineWidth', 2);
plot(tout2b, y2b, 'g-.', 'LineWidth', 2);
plot(tout2c, y2c, 'm:', 'LineWidth', 2);
plot(tout2d, y2d, 'c-', 'LineWidth', 2);
plot(tout2e, y2e, 'k-.', 'LineWidth', 2);

% 添加图例，指定每条曲线的标签
legend('y1', 'y2a', 'y2b', 'y2c', 'y2d', 'y2e');

% 添加标题和轴标签
title('Plot of Six Curves');
xlabel('Time');
ylabel('Value');

% 设置 x 轴范围为 0 到 3
xlim([0, 3]);

% 停止图形保持
hold off;