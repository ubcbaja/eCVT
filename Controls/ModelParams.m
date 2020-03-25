% Plant parameters
Jr = 0.0001;    % estimate                  [kgm^2]
Je = 0.01;      % estimate                  [kgm^2]
Be = 0.001;     % estimate                  [Nm/(rad/s)]
La = 0.02;      % estimate                  [H]
Ra = 2;         % estimate                  [ohm]
Kt = 0.283;     % torque constant           [Nm/A]
Kv = 0.105;     % voltage constant          [Vs/rad]
r = 0.005;      % moment arm                [m]
Kspring = 250;  % estimate, spring constant [N/m]
Kpot = 0.2653;  % estimate, pot constant    [V/rad]
Kpwm = 1.2;     % PWM amplitifer, 6V/5V     [V/V]
Ts = 0.0001;    % digital control time      [s]

% Compensator parameters
Wc = 2*pi*10;                       % 100Hz target
PM = 70;                        	% PM to add
G_Wc = 0.003;                       % abs gain at Wc
alpha = (1+sind(PM))/(1-sind(PM));
tau = 1/(Wc*sqrt(alpha));

% Proportional and derivative gains
Kp = (1/(G_Wc*sqrt(alpha))) + 500;
Kd = 20;

%% Plotting for dossier

figure();
subplot(1, 2, 1);
plot(theta_comp_tout, theta_comp);
hold on;
plot(theta_Kd2_tout, theta_Kd2);
plot(theta_Kd4_tout, theta_Kd4);
plot(theta_Kd8_tout, theta_Kd8);
grid on;
legend("Compensator only", "Kd = 2", "Kd = 4", "Kd = 8");
ylim([0 5]);
ylabel("Angle (rad)");
xlabel("Time (s)");
title("Overshoot Tuning");

subplot(1, 2, 2);
plot(theta_Kd8_KpP100_tout, theta_Kd8_KpP100);
hold on;
plot(theta_Kd8_KpP200_tout, theta_Kd8_KpP200);
plot(theta_Kd20_KpP200_tout, theta_Kd20_KpP200);
plot(theta_Kd20_KpP500_tout, theta_Kd20_KpP500);
grid on;
legend("Kp = 100, Kd = 8", "Kp = 200, Kd = 8", ...
    "Kp = 200, Kd = 20", "Kp = 500, Kd = 20");
ylim([0 5]);
ylabel("Angle (rad)");
xlabel("Time (s)");
title("Rise Time Tuning");

figure();
plot(theta_Kd200_KpP1000_Z_tout, theta_Kd200_KpP1000_Z);
grid on;
legend("Kp = 1000, Kd = 200, Ts = 0.0001");
ylim([0 5]);
ylabel("Angle (rad)");
xlabel("Time (s)");
title("Final Discrete Step Response");