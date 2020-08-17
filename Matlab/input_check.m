clc;
clear all;
close all;
a=arduino('COM16');
a.pinMode(35,'output');
pinMode(a,34,'output');
a.digitalWrite(35, 0);
i=0;
while(i<50)
    i = i + 1
    pause(2);
a.digitalWrite(34, 1);
    pause(2);
    a.digitalWrite(34, 0);
end