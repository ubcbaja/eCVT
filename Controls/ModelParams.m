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

% Compensator parameters
Wc = 2*pi*10;                               % 10Hz target
PM = 97;                                    % PM to add
G_Wc = 0.003;                               % abs gain at Wc
alpha = (1+sind(PM))/(1-sind(PM));
tau = 1/(Wc*sqrt(alpha));
Kp = 1/(G_Wc*sqrt(alpha));

% PID gains
% Kp = 111.1;
% Ki = 734.4;
% Kd = 210.78;
