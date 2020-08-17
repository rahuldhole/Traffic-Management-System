% clear all;
% close all;
% clc;
% % vid = videoinput('winvideo', 1, 'YUY2_320x240');
% % preview(vid);
% % start(vid);
% % pause(2);
% % im = getsnapshot(vid);
% % rgbmap = ycbcr2rgb(im);
% % %figure,imshow(rgbmap);  
% % figure,imshow(rgbmap);
% % 
% % dt = datestr(now,'yyyy-mmmm-dd AM HH.MM.SS.FFF');
% % dt = strcat(dt,'.png');
% % imwrite(I,dt);
%         
% a=arduino('COM15');
% a.pinMode(13, 'output');
% for i=0:0.2:1
%     pause(2);
%     a.digitalWrite(13,0);
%     pause(1);
%     camINTRNv = a.digitalRead(2)
%         camINTRWv = a.digitalRead(3)
%         camINTRSv = a.digitalRead(4)
%         camINTREv = a.digitalRead(5)
%         a.digitalWrite(13,1);
% end
% 
% % %             newName=datestr(DateVector)
% % %             s = sprintf('%s %d.jpg',newName,ssa);
% %             imwrite(rgbmap,'myGray.png');
% % 
% % f = fopen('C:\Users\KISMAT\Pictures\Screenshots\Screenshot (1).png'); 
% %    d = fread(f,Inf,'*uint8'); % Read in byte stream of MP3 file 
% % 
% %   str = urlreadpost('http://tms.rahuldhole.com/imgdb/mat_img.php', ... 
% %           {'image_name','Testing','file',d,'version','3','api_key','API-KEY','wait','Y'});
% %         str
% 
% 
% 
% 
% 
% 
% 
% 
% 
% 
% 
% %%%%%%Interrupt Code
% 
%         %%
%         if(~handles.INTRon)
%         %% Desktop Interrupt
%         sigstatNv = 0;
%         sigstatWv = 0;
%         sigstatSv = 0;
%         sigstatEv = 0;
%         sigstatNv = digitalRead(a, sigstatN);
%         sigstatWv = digitalRead(a, sigstatW);
%         sigstatSv = digitalRead(a, sigstatS);
%         sigstatEv = digitalRead(a, sigstatE);
%         %% Internet Interrupt
%         str = '0';
%         %INTRurl = 'http://tms.rahuldhole.com/imgdb/interrupt.php';
%         %fullURLN = strcat(INTRurl,'?INTR');
%         %str = urlread();
%         end
%         
%         if(strcmp(textString,'N') || strcmp(str,'N'))
%             handles.INTRon = 1;
%             a.digitalWrite(SendINTRN, 1);
%             set(handles.text27,'String','North Interrupt');
%             if(sigstatNv)
%             a.digitalWrite(SendINTRN, 0);
%             set(handles.edit9,'String','null');    
%             set(handles.text27,'String','North Interrupt verified');
%             end
%         end
%         
%          if(strcmp(textString,'W') || strcmp(str,'W'))
%              handles.INTRon = 1;
%              a.digitalWrite(SendINTRW, 1);
%             set(handles.text27,'String','West Interrupt');
%             if(sigstatWv)
%             a.digitalWrite(SendINTRW, 0);
%             set(handles.edit9,'String','null');    
%             set(handles.text27,'String','West Interrupt verified');
%             end
%          end
%          
%          if(strcmp(textString,'S') || strcmp(str,'S'))
%              handles.INTRon = 1;
%              a.digitalWrite(SendINTRS, 1);
%             set(handles.text27,'String','South Interrupt');
%             if(sigstatSv)
%             a.digitalWrite(SendINTRS, 0);
%             set(handles.edit9,'String','null');    
%             set(handles.text27,'String','South Interrupt verified');
%             end
%          end
%          
%          if(strcmp(textString,'E') || strcmp(str,'E'))
%              handles.INTRon = 1;
%              a.digitalWrite(SendINTRE, 1);
%             set(handles.text27,'String','East Interrupt');
%             if(sigstatEv)
%             a.digitalWrite(SendINTRE, 0);
%             set(handles.edit9,'String','null');    
%             set(handles.text27,'String','East Interrupt verified');
%             end
%          end
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 
% 		 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Capture
% 		 
% 		         %%Capture and upload
%         %%North Cam
%         if(handles.CamVeriNTimer~=0)
%             handles.CamVeriNTimer = handles.CamVeriNTimer-1;
%             guidata(hObject, handles);
%         end
%         if(handles.CamVeriNTimer==0)
%             a.digitalWrite(CamVeriN,0);
%         end
%         if(camINTRNv==1 && sigstatNv == 0)  
%             handles.emptyN = 0;
%             %for ACK to arduino 
%             handles.CamVeriNTimer = 7;
%             guidata(hObject, handles);
%             set(handles.text27,'String','Signal break: North'); 
%             if(handles.cam1)
%                 im = getsnapshot(vidN);
%                 set(handles.text27,'String','Signal break: North>Image Captured'); 
%                 rgbmap = ycbcr2rgb(im);
%                 dt = datestr(now,'yyyy-mmmm-dd AM HH.MM.SS.FFF');
%                 dt = strcat('North ',dt,'.jpg');
%                 imwrite(rgbmap, dt);
%                 %camera capture verification
%                 a.digitalWrite(CamVeriN,1);
%                 f = fopen(dt); 
%                 d = fread(f,Inf,'*uint8'); % Read in byte stream of file 
%                 str=0;
%                 str = urlreadpost('http://tms.rahuldhole.com/imgdb/mat_img.php', ... 
%                   {'image_name','North','file',d,'version','3','api_key','API-KEY','wait','Y'});
%             end
%         end
%         %%West Cam
%          if(handles.CamVeriWTimer~=0)
%             handles.CamVeriWTimer = handles.CamVeriWTimer-1;
%             guidata(hObject, handles);
%         end
%         if(handles.CamVeriWTimer==0)
%             a.digitalWrite(CamVeriW,0);
%         end
%         if(camINTRWv==1 && sigstatWv == 0)  
%             handles.emptyW = 0;
%             %for ACK to arduino 
%             handles.CamVeriWTimer = 7;
%             guidata(hObject, handles);
%             set(handles.text27,'String','Signal break: West'); 
%             if(handles.cam2)
%                 im = getsnapshot(vidW);
%                 set(handles.text27,'String','Signal break: West>Image Captured'); 
%                 rgbmap = ycbcr2rgb(im);
%                 dt = datestr(now,'yyyy-mmmm-dd AM HH.MM.SS.FFF');
%                 dt = strcat('West ',dt,'.jpg');
%                 imwrite(rgbmap, dt);
%                 %camera capture verification
%                 a.digitalWrite(CamVeriW,1);
%                 f = fopen(dt); 
%                 d = fread(f,Inf,'*uint8'); % Read in byte stream of file 
%                 str=0;
%                 str = urlreadpost('http://tms.rahuldhole.com/imgdb/mat_img.php', ... 
%                   {'image_name','West','file',d,'version','3','api_key','API-KEY','wait','Y'});
%             end
%         end
%         %%South Cam
%          if(handles.CamVeriSTimer~=0)
%             handles.CamVeriSTimer = handles.CamVeriSTimer-1;
%             guidata(hObject, handles);
%         end
%         if(handles.CamVeriSTimer==0)
%             a.digitalWrite(CamVeriS,0);
%         end
%         if(camINTRSv==1 && sigstatSv == 0)  
%             handles.emptyS = 0;
%             %for ACK to arduino 
%             handles.CamVeriSTimer = 7;
%             guidata(hObject, handles);
%             set(handles.text27,'String','Signal break: South'); 
%             if(handles.cam3)
%                 im = getsnapshot(vidS);
%                 set(handles.text27,'String','Signal break: South>Image Captured'); 
%                 rgbmap = ycbcr2rgb(im);
%                 dt = datestr(now,'yyyy-mmmm-dd AM HH.MM.SS.FFF');
%                 dt = strcat('South ',dt,'.jpg');
%                 imwrite(rgbmap, dt);
%                 %camera capture verification
%                 a.digitalWrite(CamVeriS,1);
%                 f = fopen(dt); 
%                 d = fread(f,Inf,'*uint8'); % Read in byte stream of file 
%                 str=0;
%                 str = urlreadpost('http://tms.rahuldhole.com/imgdb/mat_img.php', ... 
%                   {'image_name','South','file',d,'version','3','api_key','API-KEY','wait','Y'});
%             end
%         end
%         %%East Cam
%          if(handles.CamVeriETimer~=0)
%             handles.CamVeriETimer = handles.CamVeriETimer-1;
%             guidata(hObject, handles);
%         end
%         if(handles.CamVeriETimer==0)
%             a.digitalWrite(CamVeriE,0);
%         end
%         if(camINTREv==1 && sigstatEv == 0)  
%             handles.emptyE = 0;
%             %for ACK to arduino 
%             handles.CamVeriETimer = 7;
%             guidata(hObject, handles);
%             set(handles.text27,'String','Signal break: East'); 
%             if(handles.cam4)
%                 im = getsnapshot(vidE);
%                 set(handles.text27,'String','Signal break: East>Image Captured'); 
%                 rgbmap = ycbcr2rgb(im);
%                 dt = datestr(now,'yyyy-mmmm-dd AM HH.MM.SS.FFF');
%                 dt = strcat('East ',dt,'.jpg');
%                 imwrite(rgbmap, dt);
%                 %camera capture verification
%                 a.digitalWrite(CamVeriE,1);
%                 f = fopen(dt); 
%                 d = fread(f,Inf,'*uint8'); % Read in byte stream of file 
%                 str=0;
%                 str = urlreadpost('http://tms.rahuldhole.com/imgdb/mat_img.php', ... 
%                   {'image_name','East','file',d,'version','3','api_key','API-KEY','wait','Y'});
%             end
%         end
%         %%


f = fopen('profile2.jpg');
d = fread(f, Inf, '*uint8'); % Read in byte stream of file
                    str = 0;
                    str = urlreadpost('http://tms.rahuldhole.com/Final/blue/matlab/mat_img.php', ...
                    {'image_name', 'N', 'signo', 'IT_DEPT', 'file', d, 'version', '3', 'api_key', 'API-KEY', 'wait', 'Y'})
                