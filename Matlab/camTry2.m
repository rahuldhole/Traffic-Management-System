clear all;
clc
% vid = videoinput('gige',1,'RGB24_640x480');
% preview(vid);
imaqInfo = imaqhwinfo;
imaqInfo1=imaqInfo.InstalledAdaptors;
imaqInfo1
hwInfo = imaqhwinfo('winvideo')

device1 = hwInfo.DeviceInfo(1)

device1.DeviceID
device1.DefaultFormat
device1.SupportedFormats
vidobj = videoinput('winvideo', 1);

% Open the preview window.
preview(vidobj)
