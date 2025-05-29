% Default parameters for electric aircraft examples
%
% Copyright 2017-2023 The MathWorks, Inc.

% Default parameters
battery_capacity        = 4.5;
battery_vnom            = 22.8;
battery_pdensity        = 201;
engine_system_mass      = 0;
payload_mass            = 0;
payload_mass_workspace  = 0;
g_norm                  = 9.8;
max_thrust              = 65.87;
thrust_tau              = 0.1;
thrust_eff              = 0.8;

gen_torque_demand = 0.389;       % Torque input to generator in N*m
engine_ref_speed  = 4824;     % Engine RPM command in rpm
motor_ref_speed   = 4824;     % Engine RPM command in rpm

% Initialize Values
HeightBasedProfile = Simulink.Variant('FlightProfileType == 1');
TimeBasedProfile = Simulink.Variant('FlightProfileType == 2');
FlightProfileType = 1;

init_height_type = 0;

% Get flight profile information from Parameter Structure:
FlightProfileChoice = FlightProfileStruct(1);
FlightProfileType = FlightProfileChoice.type;
FlightProfileLength = FlightProfileChoice.FlightProfileLength;

