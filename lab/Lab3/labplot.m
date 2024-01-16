% 创建一个新的图形窗口
figure;

% 绘制第一条曲线
plot(tout10, y10, 'r-', 'LineWidth', 2); % 使用红色实线

hold on; % 在同一图中绘制下一条曲线

% 绘制第二条曲线
plot(tout20, y20, 'g--', 'LineWidth', 2); % 使用绿色虚线

% 绘制第三条曲线
plot(tout30, y30, 'b--', 'LineWidth', 2); % 使用蓝色点线
% 添加标题、标签和图例
title('Disturbance Responce in Unit Step.');
xlabel('Time');
ylabel('Reference Response');
legend('Controller 1', 'Controller 2', 'Controller 3');

% 在图上添加网格线
grid on;

% 可以使用hold off结束绘制
hold off;