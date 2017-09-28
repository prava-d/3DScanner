clf

figure(1)
plot(Voltage, Distance, 'b.')

cali = fit(Voltage,Distance,'exp1')
hold on
plot(cali,'r-');

plot(Voltage_test,Distance_test, 'g.')

xlabel('Voltage (V)');
ylabel('Distance (m)');
title('Calibration of Distance to Voltage');
legend('Data', 'Fit Line', 'Test Points', 'Error Bars');

% figure(2)
% plot(cali,'r-');
% hold on
errorbar(Voltage_test,Distance_test,(cali(Voltage_test)-Distance_test))
% xlabel('Voltage (V)');
% ylabel('Distance (m)');
% title('Calibration of Distance to Voltage');
% legend('Fit Line', 'Test Points');

plot(Voltage_test,Distance_test, 'g.')