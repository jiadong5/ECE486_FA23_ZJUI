% Assuming you have the variables tout, y, and y_dot in your workspace

% Plot y vs. time (tout)
figure; % Create a new figure window
plot(out.tout, out.y);
title('y vs. Time');
xlabel('Time');
ylabel('y');

xlim([0,3]);

% Create a new figure for y_dot
figure; % Create another new figure window
plot(out.tout, out.y_dot);
title('y_{dot} vs. Time');
xlabel('Time');
ylabel('y_{dot}');

xlim([0,3]);