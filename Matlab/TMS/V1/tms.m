function varargout = tms(varargin)
% tms MATLAB code for tms.fig
%      tms, by itself, creates a new tms or raises the existing
%      singleton*.
%
%      H = tms returns the handle to a new tms or the handle to
%      the existing singleton*.
%
%      tms('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in tms.M with the given input arguments.
%
%      tms('Property','Value',...) creates a new tms or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before tms_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to tms_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help tms

% Last Modified by GUIDE v2.5 15-Mar-2016 19:19:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @tms_OpeningFcn, ...
                   'gui_OutputFcn',  @tms_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before tms is made visible.
function tms_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to tms (see VARARGIN)

% Choose default command line output for tms
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
handles.cam1 = 0;
handles.cam2 = 0;
handles.cam3 = 0;
handles.cam4 = 0;
handles.vidN = 0;
handles.vidW = 0;
handles.vidS = 0;
handles.vidE = 0;

handles.a= 0;

handles.CamINTRN = 2;
handles.CamINTRW = 3;
handles.CamINTRS = 4;
handles.CamINTRE = 5;

%%Send INTR
handles.SendINTRN = 6;
handles.SendINTRW = 7;
handles.SendINTRS = 8;
handles.SendINTRE = 9;
handles.SendINTREmpty = 18;
handles.SendINTREmptyV = 0;

handles.INTRon = 0;

handles.CamVeriN = 10;
handles.CamVeriW = 11;
handles.CamVeriS = 12;
handles.CamVeriE = 13;

handles.CamVeriNTimer = 0;
handles.CamVeriWTimer = 0;
handles.CamVeriSTimer = 0;
handles.CamVeriETimer = 0;


%%Sig.Stat
handles.sigstatN = 14;
handles.sigstatW = 15;
handles.sigstatS = 16;
handles.sigstatE = 17;
handles.i = 0;

%timer for no traffic detection
handles.emptyN = 0;
handles.emptyW = 0;
handles.emptyS = 0;
handles.emptyE = 0;

guidata(hObject, handles);

% UIWAIT makes tms wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = tms_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function comIn_Callback(hObject, ~, handles)
% hObject    handle to comIn (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of comIn as text
%        str2double(get(hObject,'String')) returns contents of comIn as a double


% --- Executes during object creation, after setting all properties.
function comIn_CreateFcn(hObject, eventdata, handles)
% hObject    handle to comIn (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in COM_PORT.
function COM_PORT_Callback(hObject, eventdata, handles)

% hObject    handle to COM_PORT (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%%
%%
%%Declare vars
CamINTRN = handles.CamINTRN;
CamINTRW = handles.CamINTRW;
CamINTRS = handles.CamINTRS;
CamINTRE = handles.CamINTRE;

SendINTRN = handles.SendINTRN;
SendINTRW = handles.SendINTRW;
SendINTRS = handles.SendINTRS;
SendINTRE = handles.SendINTRE;

sigstatN = handles.sigstatN;
sigstatW = handles.sigstatW;
sigstatS = handles.sigstatS;
sigstatE = handles.sigstatE;


CamVeriN = handles.CamVeriN;
CamVeriW = handles.CamVeriW;
CamVeriS = handles.CamVeriS;
CamVeriE = handles.CamVeriE;
%%Read input COM port
textString = get(handles.comIn,'String');
if(length(textString)<3)
set(handles.text27,'String','Please enter valid COM port.');
end
%%
%%On arduino connected
if(length(textString)>3)
    %%except that demo after completion of code
    a = handles.a;
    set(handles.text27,'String','Connecting...');
a=arduino(textString);

pinMode(a,sigstatN,'input');
pinMode(a,sigstatW,'input');
pinMode(a,sigstatS,'input');
pinMode(a,sigstatE,'input');

pinMode(a,CamINTRN,'input');
pinMode(a,CamINTRW,'input');
pinMode(a,CamINTRS,'input');
pinMode(a,CamINTRE,'input');

pinMode(a,SendINTRN,'output');
pinMode(a,SendINTRW,'output');
pinMode(a,SendINTRS,'output');
pinMode(a,SendINTRE,'output');


pinMode(a,CamVeriN,'output');
pinMode(a,CamVeriW,'output');
pinMode(a,CamVeriS,'output');
pinMode(a,CamVeriE,'output');

handles.a = a;
guidata(hObject,handles);
end
if(a==0)
set(handles.text27,'String','Please connect Arduino USB cable and enter valid COM port.');
end
if(a~=0)
set(handles.text27,'String','Arduino MATLAB conection established successfully');
end

% --- Executes on button press in pushbutton10.
function pushbutton10_Callback(hObject, eventdata, handles)
if(handles.cam2)
preview(handles.vidW);
end
if(~handles.cam2)
set(handles.text27,'String','West side Camera is off please turn on');
end
% hObject    handle to pushbutton10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton12.
function pushbutton12_Callback(hObject, eventdata, handles)
if(handles.cam4)
preview(handles.vidE);
end
if(~handles.cam4)
set(handles.text27,'String','East side Camera is off please turn on');
end
% hObject    handle to pushbutton12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton14.
function pushbutton14_Callback(hObject, eventdata, handles)

if(handles.cam4)
preview(handles.vidE);
end
if(~handles.cam4)
set(handles.text27,'String','East side Camera is off please turn on');
end

if(handles.cam3)
preview(handles.vidS);
end
if(~handles.cam3)
set(handles.text27,'String','South side Camera is off please turn on');
end

if(handles.cam2)
preview(handles.vidW);
end
if(~handles.cam2)
set(handles.text27,'String','West side Camera is off please turn on');
end

if(handles.cam1)
preview(handles.vidN);
end
if(~handles.cam1)
set(handles.text27,'String','North side Camera is off please turn on');
end
% hObject    handle to pushbutton14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%vidN = get(hObject,'Userdata');

%preview(vidN);%preview
%start(vidN);%start video

% --- Executes on button press in pushbutton6.
function pushbutton6_Callback(hObject, eventdata, handles)
if(handles.cam1)
preview(handles.vidN);
end
if(~handles.cam1)
set(handles.text27,'String','North side Camera is off please turn on');
end
    
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton8.
function pushbutton8_Callback(hObject, eventdata, handles)
if(handles.cam3)
preview(handles.vidS);
end
if(~handles.cam3)
set(handles.text27,'String','South side Camera is off please turn on');
end
% hObject    handle to pushbutton8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton15.
function pushbutton15_Callback(hObject, eventdata, handles)

% hObject    handle to pushbutton15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%%vid driver for all cameras
%vidN = videoinput('winvideo', 1, 'YUY2_320x240');%North Camera
%vid = 120454;
%set(hObject,'Userdata',vid);
%set(handles.hObject,'Userdata',vidN);
%%
vidN = handles.vidN;
vidW = handles.vidW;
vidS = handles.vidS;
vidE = handles.vidE;
%%
set(handles.text27,'String','Please connect north side camera...');
vidN = videoinput('winvideo', 1, 'YUY2_320x240');%North Camera
if(vidN~=0)
    set(handles.text27,'String','North side camera connected');
start(vidN);%start video
handles.cam1 = 1;
handles.vidN = vidN;
guidata(hObject, handles);
end

set(handles.text27,'String','Please connect west side camera...');
vidW = videoinput('winvideo', 2, 'YUY2_320x240');%North Camera
if(vidW~=0)
    set(handles.text27,'String','West side camera connected');
start(vidW);%start video
handles.cam2 = 1;
handles.vidW = vidW;
guidata(hObject, handles);
end

set(handles.text27,'String','Please connect south side camera...');
vidS = videoinput('winvideo', 3, 'YUY2_320x240');%North Camera
if(vidS~=0)
    set(handles.text27,'String','South side camera connected');
start(vidS);%start video
handles.cam3 = 1;
handles.vidS = vidS;
guidata(hObject, handles);
end

set(handles.text27,'String','Please connect east side camera...');
vidE = videoinput('winvideo', 4, 'YUY2_320x240');%North Camera
if(vidE~=0)
    set(handles.text27,'String','East side camera connected');
start(vidE);%start video
handles.cam4 = 1;
handles.vidE = vidE;
guidata(hObject, handles);

end


% --- Executes on button press in pushbutton20.
function pushbutton20_Callback(hObject, eventdata, handles)
set(handles.text27,'String','Please connect west side camera...');
handles.vidW = videoinput('winvideo', 2, 'YUY2_320x240');%West Camera
if(handles.vidW~=0)
    set(handles.text27,'String','West side camera connected');
start(handles.vidW);%start video
handles.cam2 = 1;
guidata(hObject, handles);
end
% hObject    handle to pushbutton20 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton21.
function pushbutton21_Callback(hObject, eventdata, handles)
set(handles.text27,'String','Please connect east side camera...');
handles.vidE = videoinput('winvideo', 1, 'YUY2_320x240');%East Camera
if(handles.vidE~=0)
    set(handles.text27,'String','East side camera connected');
start(handles.vidE);%start video
handles.cam4 = 1;
guidata(hObject, handles);
end
% hObject    handle to pushbutton21 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in cam1.
function cam1_Callback(hObject, eventdata, handles)
%vidN = handles.vidN;
set(handles.text27,'String','Please connect north side camera...');
handles.vidN = videoinput('winvideo', 1, 'YUY2_320x240');%North Camera
if(handles.vidN~=0)
    set(handles.text27,'String','North side camera connected');
start(handles.vidN);%start video
handles.cam1 = 1;
guidata(hObject, handles);
end
% hObject    handle to cam1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton23.
function pushbutton23_Callback(hObject, eventdata, handles)
    set(handles.text27,'String','Please connect south side camera...');
handles.vidS = videoinput('winvideo', 3, 'YUY2_320x240');%North Camera
if(handles.vidS~=0)
    set(handles.text27,'String','South side camera connected');
start(handles.vidS);%start video
handles.cam3 = 1;
guidata(hObject, handles);
end
% hObject    handle to pushbutton23 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
delete(hObject);


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over cam1.
function cam1_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to cam1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton24.
function pushbutton24_Callback(hObject, eventdata, handles)
CamINTRN = handles.CamINTRN;
CamINTRW = handles.CamINTRW;
CamINTRS = handles.CamINTRS;
CamINTRE = handles.CamINTRE;

%%Send INTR
SendINTRN = handles.SendINTRN;
SendINTRW = handles.SendINTRW;
SendINTRS = handles.SendINTRS;
SendINTRE = handles.SendINTRE;

%%Sig.Stat
sigstatN = handles.sigstatN;
sigstatW = handles.sigstatW;
sigstatS = handles.sigstatS;
sigstatE = handles.sigstatE;

%%
vidN = handles.vidN;
vidW = handles.vidW;
vidS = handles.vidS;
vidE = handles.vidE;

%%
cam1= handles.cam1;
cam2= handles.cam2;
cam3= handles.cam3;
cam4= handles.cam4;

CamVeriN = handles.CamVeriN;
CamVeriW = handles.CamVeriW;
CamVeriS = handles.CamVeriS;
CamVeriE = handles.CamVeriE;

CamVeriNTimer = handles.CamVeriNTimer;
CamVeriWTimer = handles.CamVeriWTimer;
CamVeriSTimer = handles.CamVeriSTimer;
CamVeriETimer = handles.CamVeriETimer;
set(handles.text27,'String','Starting...');
%%
a = handles.a;
if(a==0)
    set(handles.text27,'String','Please connect arduino...');
end
if(a~=0)
    set(handles.text27,'String','Starting...');
    set(handles.edit9,'String','start');
    while  1
        a.digitalWrite(SendINTRN, 0);
        a.digitalWrite(SendINTRW, 0);
        a.digitalWrite(SendINTRS, 0);
        a.digitalWrite(SendINTRE, 0);
        %%
        %%in while
        %%Check if stop click
        textString = get(handles.edit9,'String');
        if(strcmp(textString,'stop'))
            set(handles.text27,'String','stop break');
            break;
        end
        %%
        %%in while
        %%Update signal status
        sigstatNv = 0;
        sigstatWv = 0;
        sigstatSv = 0;
        sigstatEv = 0;

        sigstatNv = digitalRead(a, sigstatN);
        sigstatWv = digitalRead(a, sigstatW);
        sigstatSv = digitalRead(a, sigstatS);
        sigstatEv = digitalRead(a, sigstatE);
        url = 'http://tms.rahuldhole.com/Final/blue/matlab/sigstat.php?signo=IT_DEPT&';
        if(sigstatNv==1)
            if(handles.SendINTREmptyV == 4)
                handles.SendINTREmptyV = 0;
                guidata(hObject, handles);
            end
        fullURL = strcat(url, 'state=', 'N');
        str = 0;
        set(handles.text27,'String','Uploading north signal status'); 
        str = urlread(fullURL);
        if(str)
           set(handles.text27,'String','North signal status updated...'); 
        end
        end
        
        if(sigstatWv==1)
            if(handles.SendINTREmptyV == 1)
                handles.SendINTREmptyV = 0;
                guidata(hObject, handles);
            end
        fullURL = strcat(url, 'state=', 'W');
        str = 0;
        set(handles.text27,'String','Uploading west signal status'); 
        str = urlread(fullURL);
        if(str)
           set(handles.text27,'String','West signal status updated...'); 
        end
        end
        
        if(sigstatSv==1)
            if(handles.SendINTREmptyV == 2)
                handles.SendINTREmptyV = 0;
                guidata(hObject, handles);
            end
        fullURL = strcat(url, 'state=', 'S');
        str = 0;
        set(handles.text27,'String','Uploading south signal status'); 
        str = urlread(fullURL);
        if(str)
           set(handles.text27,'String','South signal status updated...'); 
        end
        end
        
        if(sigstatEv==1)
            if(handles.SendINTREmptyV == 3)
                handles.SendINTREmptyV = 0;
                guidata(hObject, handles);
            end
        fullURL = strcat(url, 'state=', 'E');
        str = 0;
        set(handles.text27,'String','Uploading east signal status'); 
        str = urlread(fullURL);
        if(str)
           set(handles.text27,'String','East signal status updated...'); 
        end
        end
        %%
        %%in while
        %%Check camera interrupts
        camINTRNv = 0;
        camINTRWv = 0;
        camINTRSv = 0;
        camINTREv = 0;  
        pause(1);
        camINTRNv = a.digitalRead(CamINTRN)
        camINTRWv = a.digitalRead(CamINTRW)
        camINTRSv = a.digitalRead(CamINTRS)
        camINTREv = a.digitalRead(CamINTRE)
        
        %set(handles.text27, 'String', stat);
        
        % % Capture and upload
        % % North Cam
        if (camINTRNv == 1)
            handles.emptyN = 0;
            handles.CamVeriNTimer = 7;
            guidata(hObject, handles);
            if(sigstatNv == 0)
                set(handles.text27, 'String', 'Signal break: North');
                if (handles.cam1)
                    im = getsnapshot(vidN);
                    set(handles.text27, 'String', 'Signal break: North>Image Captured');
                    rgbmap = ycbcr2rgb(im);
                    dt = datestr(now, 'yyyy-mmmm-dd AM HH.MM.SS.FFF');
                    dt = strcat('North ', dt, '.jpg');
                    imwrite(rgbmap, dt);
                    % camera capture verification
                    a.digitalWrite(CamVeriN, 1);
                    f = fopen(dt);
                    d = fread(f, Inf, '*uint8'); % Read in byte stream of file
                    str = 0;
                    str = urlreadpost('http://tms.rahuldhole.com/Final/blue/matlab/mat_img.php', ...
                    {'image_name', 'N', 'signo', 'IT_DEPT', 'file', d, 'version', '3', 'api_key', 'API-KEY', 'wait', 'Y'});
                end
            end
        end
        if (handles.CamVeriNTimer > 0)
            handles.CamVeriNTimer = handles.CamVeriNTimer - 1;
            guidata(hObject, handles);
        end
        if (handles.CamVeriNTimer == 0)
            a.digitalWrite(CamVeriN, 0);
        end
        %West
        if (camINTRWv == 1)
        handles.emptyW = 0;
        handles.CamVeriWTimer = 7;
        guidata(hObject, handles);
        if(sigstatWv == 0)
            set(handles.text27, 'String', 'Signal break: West');
            if (handles.cam2)
                im = getsnapshot(vidW);
                set(handles.text27, 'String', 'Signal break: West>Image Captured');
                rgbmap = ycbcr2rgb(im);
                dt = datestr(now, 'yyyy-mmmm-dd AM HH.MM.SS.FFF');
                dt = strcat('West ', dt, '.jpg');
                imwrite(rgbmap, dt);
                a.digitalWrite(CamVeriW, 1);
                f = fopen(dt);
                d = fread(f, Inf, '*uint8'); % Read in byte stream of file
                str = 0;
                str = urlreadpost('http://tms.rahuldhole.com/imgdb/mat_img.php', ...
                    {'image_name', 'W', 'file', d, 'version', '3', 'api_key', 'API-KEY', 'wait', 'Y'});
                end
            end
        end
        if (handles.CamVeriWTimer > 0)
            handles.CamVeriWTimer = handles.CamVeriWTimer - 1;
            guidata(hObject, handles);
        end
        if (handles.CamVeriWTimer == 0)
            a.digitalWrite(CamVeriW, 0);
        end
       %South
       if (camINTRSv == 1)
        handles.emptyS = 0;
        handles.CamVeriSTimer = 7;
        guidata(hObject, handles);
        if(sigstatSv == 0)
            set(handles.text27, 'String', 'Signal break: South');
            if (handles.cam3)
                im = getsnapshot(vidS);
                set(handles.text27, 'String', 'Signal break: South>Image Captured');
                rgbmap = ycbcr2rgb(im);
                dt = datestr(now, 'yyyy-mmmm-dd AM HH.MM.SS.FFF');
                dt = strcat('South ', dt, '.jpg');
                imwrite(rgbmap, dt);
                a.digitalWrite(CamVeriS, 1);
                f = fopen(dt);
                d = fread(f, Inf, '*uint8'); % Read in byte stream of file
                str = 0;
                str = urlreadpost('http://tms.rahuldhole.com/imgdb/mat_img.php', ...
                {'image_name', 'S', 'file', d, 'version', '3', 'api_key', 'API-KEY', 'wait', 'Y'});
                end
            end
        end
        if (handles.CamVeriSTimer > 0)
            handles.CamVeriSTimer = handles.CamVeriSTimer - 1;
            guidata(hObject, handles);
        end
        if (handles.CamVeriSTimer == 0)
            a.digitalWrite(CamVeriS, 0);
        end
        %East
        if (camINTREv == 1)
        handles.emptyE = 0;
        handles.CamVeriETimer = 7;
        guidata(hObject, handles);
        if(sigstatEv == 0)
            set(handles.text27, 'String', 'Signal break: East');
            if (handles.cam4)
                im = getsnapshot(vidE);
                set(handles.text27, 'String', 'Signal break: East>Image Captured');
                rgbmap = ycbcr2rgb(im);
                dt = datestr(now, 'yyyy-mmmm-dd AM HH.MM.SS.FFF');
                dt = strcat('East ', dt, '.jpg');
                imwrite(rgbmap, dt);
                a.digitalWrite(CamVeriE, 1);
                f = fopen(dt);
                d = fread(f, Inf, '*uint8'); % Read in byte stream of file
                str = 0;
                str = urlreadpost('http://tms.rahuldhole.com/imgdb/mat_img.php', ...
                {'image_name', 'E', 'file', d, 'version', '3', 'api_key', 'API-KEY', 'wait', 'Y'});
                end
            end
        end
        if (handles.CamVeriETimer > 0)
            handles.CamVeriETimer = handles.CamVeriETimer - 1;
            guidata(hObject, handles);
        end
        if (handles.CamVeriETimer == 0)
            a.digitalWrite(CamVeriE, 0);
        end
        %%End CamIntr
        %%
        %%Inactive road closing signal\
		%%North
        if(camINTRNv==0 )
				if(sigstatNv == 1)
					handles.emptyN = handles.emptyN+1;
					guidata(hObject, handles);
					%if 5000 appx. 5 seconds inactive
					if(handles.emptyN>5000)
						%%Interrupting 
                        handles.SendINTREmptyV = 1;
                        guidata(hObject, handles);
						a.digitalWrite(handles.SendINTREmpty, 1);
						set(handles.text27,'String','No traffic on North side signal hence closing signal.');
					end
				end
				if(sigstatNv == 0)
                    handles.SendINTREmptyV = 0;
					handles.emptyN = 0;
					guidata(hObject, handles);
				end
        end
        %%West Inactive
        if(camINTRWv==0 )
				if(sigstatWv == 1)
					handles.emptyW = handles.emptyW+1;
					guidata(hObject, handles);
					%if 5000 appx. 5 seconds inactive
					if(handles.emptyW>5000)
						%%Interrupting 
                        handles.SendINTREmptyV = 2;
                        guidata(hObject, handles);
						a.digitalWrite(handles.SendINTREmpty, 1);
						set(handles.text27,'String','No traffic on West side signal hence closing signal.');
					end
				end
				if(sigstatWv == 0)
                    handles.SendINTREmptyV = 0;
					handles.emptyW = 0;
					guidata(hObject, handles);
				end
        end
        %%South Inactive
                if(camINTRSv==0 )
				if(sigstatSv == 1)
					handles.emptyS = handles.emptyS+1;
					guidata(hObject, handles);
					%if 5000 appx. 5 seconds inactive
					if(handles.emptyS>5000)
						%%Interrupting 
                        handles.SendINTREmptyV = 3;
                        guidata(hObject, handles);
						a.digitalWrite(handles.SendINTREmpty, 1);
						set(handles.text27,'String','No traffic on South side signal hence closing signal.');
					end
				end
				if(sigstatSv == 0)
                    handles.SendINTREmptyV = 0;
					handles.emptyS = 0;
					guidata(hObject, handles);
				end
        end
        %%East Inactive
                if(camINTREv==0 )
				if(sigstatEv == 1)
					handles.emptyE = handles.emptyE+1;
					guidata(hObject, handles);
					%if 5000 appx. 5 seconds inactive
					if(handles.emptyE>5000)
						%%Interrupting 
                        handles.SendINTREmptyV = 4;
                        guidata(hObject, handles);
						a.digitalWrite(handles.SendINTREmpty, 1);
						set(handles.text27,'String','No traffic on East side signal hence closing signal.');
					end
				end
				if(sigstatEv == 0)
                    handles.SendINTREmptyV = 0;
					handles.emptyE = 0;
					guidata(hObject, handles);
                end
                end
                %%
                %%end
    end  
end

% hObject    handle to pushbutton24 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

%%
% --- Executes on button press in pushbutton25.
function pushbutton25_Callback(hObject, eventdata, handles)
set(handles.edit9,'String','stop');

% hObject    handle to pushbutton25 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton26.
function pushbutton26_Callback(hObject, eventdata, handles)
set(handles.edit9,'String','N');
% hObject    handle to pushbutton26 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton27.
function pushbutton27_Callback(hObject, eventdata, handles)
set(handles.edit9,'String','S');
% hObject    handle to pushbutton27 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton28.
function pushbutton28_Callback(hObject, eventdata, handles)
set(handles.edit9,'String','W');
% hObject    handle to pushbutton28 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton29.
function pushbutton29_Callback(hObject, eventdata, handles)
set(handles.edit9,'String','E');
% hObject    handle to pushbutton29 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function uipanel28_CreateFcn(hObject, eventdata, handles)

% hObject    handle to uipanel28 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called



function edit9_Callback(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit9 as text
%        str2double(get(hObject,'String')) returns contents of edit9 as a double


% --- Executes during object creation, after setting all properties.
function edit9_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
