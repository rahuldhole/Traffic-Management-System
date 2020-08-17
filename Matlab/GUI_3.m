function varargout = GUI_3(varargin)
% GUI_3 MATLAB code for GUI_3.fig
%      GUI_3, by itself, creates a new GUI_3 or raises the existing
%      singleton*.
%
%      H = GUI_3 returns the handle to a new GUI_3 or the handle to
%      the existing singleton*.
%
%      GUI_3('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_3.M with the given input arguments.
%
%      GUI_3('Property','Value',...) creates a new GUI_3 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_3_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_3_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI_3

% Last Modified by GUIDE v2.5 15-Mar-2016 02:33:53

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_3_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_3_OutputFcn, ...
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


% --- Executes just before GUI_3 is made visible.
function GUI_3_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI_3 (see VARARGIN)

% Choose default command line output for GUI_3
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

%%Sig.Stat
handles.sigstatN = 10;
handles.sigstatW = 11;
handles.sigstatS = 12;
handles.sigstatE = 13;
handles.i = 0;
handles.emptyN = 0;
handles.emptyW = 0;
handles.emptyS = 0;
handles.emptyE = 0;

guidata(hObject, handles);

% UIWAIT makes GUI_3 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_3_OutputFcn(hObject, eventdata, handles) 
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
textString = get(handles.comIn,'String');
if(length(textString)<3)
set(handles.text27,'String','Please enter valid COM port.');
end
a = handles.a;
if(length(textString)>3)
    set(handles.text27,'String','Connecting...');
a=arduino(textString);
pinMode(a,2,'input');
pinMode(a,3,'input');
pinMode(a,4,'input');
pinMode(a,5,'input');
pinMode(a,6,'input');
pinMode(a,7,'input');
pinMode(a,8,'input');
pinMode(a,9,'output');
pinMode(a,10,'output');
pinMode(a,11,'output');
pinMode(a,12,'output');
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
if(~handles.cam2)
set(handles.text27,'String','East side Camera is off please turn on');
end
% hObject    handle to pushbutton12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton14.
function pushbutton14_Callback(hObject, eventdata, handles)
if(handles.cam1)
preview(handles.vidN);
end
if(~handles.cam1)
set(handles.text27,'String','North side Camera is off please turn on');
end

if(handles.cam2)
preview(handles.vidW);
end
if(~handles.cam2)
set(handles.text27,'String','West side Camera is off please turn on');
end

if(handles.cam3)
preview(handles.vidS);
end
if(~handles.cam3)
set(handles.text27,'String','South side Camera is off please turn on');
end

if(handles.cam4)
preview(handles.vidE);
end
if(~handles.cam4)
set(handles.text27,'String','East side Camera is off please turn on');
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
if(~handles.cam2)
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
vidW = videoinput('winvideo', 1, 'YUY2_320x240');%North Camera
if(vidW~=0)
    set(handles.text27,'String','West side camera connected');
vidW = videoinput('winvideo', 2, 'YUY2_320x240');%North Camera
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

vidE = handles.vidE;
set(handles.text27,'String','Please connect east side camera...');

if(vidS~=0)
    set(handles.text27,'String','East side camera connected');
vidE = videoinput('winvideo', 4, 'YUY2_320x240');%North Camera
start(vidE);%start video
handles.cam4 = 1;
handles.vidE = vidE;
guidata(hObject, handles);
end


% --- Executes on button press in pushbutton20.
function pushbutton20_Callback(hObject, eventdata, handles)
set(handles.text27,'String','Please connect west side camera...');
vidW = handles.vidW;
if(vidW~=0)
    set(handles.text27,'String','West side camera connected');
vidW = videoinput('winvideo', 2, 'YUY2_320x240');%North Camera
start(vidW);%start video
handles.cam2 = 1;
handles.vidW = vidW;
guidata(hObject, handles);
end
% hObject    handle to pushbutton20 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton21.
function pushbutton21_Callback(hObject, eventdata, handles)
vidE = handles.vidE;
set(handles.text27,'String','Please connect east side camera...');

if(vidS~=0)
    set(handles.text27,'String','East side camera connected');
vidE = videoinput('winvideo', 4, 'YUY2_320x240');%North Camera
start(vidE);%start video
handles.cam4 = 1;
handles.vidE = vidE;
guidata(hObject, handles);
end
% hObject    handle to pushbutton21 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in cam1.
function cam1_Callback(hObject, eventdata, handles)
vidN = handles.vidN;
set(handles.text27,'String','Please connect north side camera...');
vidN = videoinput('winvideo', 1, 'YUY2_320x240');%North Camera
if(vidN~=0)
    set(handles.text27,'String','North side camera connected');
start(vidN);%start video
handles.cam1 = 1;
handles.vidN = vidN;
guidata(hObject, handles);
end
% hObject    handle to cam1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton23.
function pushbutton23_Callback(hObject, eventdata, handles)
vidS = handles.vidS;
    set(handles.text27,'String','Please connect south side camera...');
vidS = videoinput('winvideo', 3, 'YUY2_320x240');%North Camera
if(vidS~=0)
    set(handles.text27,'String','South side camera connected');
start(vidS);%start video
handles.cam3 = 1;
handles.vidS = vidS;
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

%%
a = handles.a;
if(a==0)
    set(handles.text27,'String','Please connect arduino...');
end
if(a~=0)
    set(handles.text27,'String','Starting...');
    set(handles.edit9,'String','start');
    while  1
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
        %%Set all interrupts as null
        a.digitalWrite(SendINTRN, 0);
        a.digitalWrite(SendINTRW, 0);
        a.digitalWrite(SendINTRS, 0);
        a.digitalWrite(SendINTRE, 0);
        %%
        %%in while
        %%Update signal status
        sigstatNv = 0;
        sigstatWv = 0;
        sigstatSv = 0;
        sigstatEv = 0;
        if(a==0)
        set(handles.text27,'String','Please connect Arduino USB cable and enter valid COM port.');
        end
        if(a~=0)
        sigstatNv = digitalRead(a, sigstatN);
        sigstatWv = digitalRead(a, sigstatW);
        sigstatSv = digitalRead(a, sigstatS);
        sigstatEv = digitalRead(a, sigstatE);
        end
        if(sigstatNv==1)
        url = 'http://tms.rahuldhole.com/SendData%20To%20file%20on%20server/led.php';
        fullURL = strcat(url, '?state=', 'sn');
        str = 0;
        set(handles.text27,'String','Uploadiding north signal status'); 
        str = urlread(fullURL);
        if(str)
           set(handles.text27,'String','North signal status updated...'); 
        end
        end
        
        if(sigstatWv==1)
        url = 'http://tms.rahuldhole.com/SendData%20To%20file%20on%20server/led.php';
        fullURL = strcat(url, '?state=', 'sw');
        str = 0;
        set(handles.text27,'String','Uploadiding west signal status'); 
        str = urlread(fullURL);
        if(str)
           set(handles.text27,'String','West signal status updated...'); 
        end
        end
        
        if(sigstatSv==1)
        url = 'http://tms.rahuldhole.com/SendData%20To%20file%20on%20server/led.php';
        fullURL = strcat(url, '?state=', 'ss');
        str = 0;
        set(handles.text27,'String','Uploadiding south signal status'); 
        str = urlread(fullURL);
        if(str)
           set(handles.text27,'String','South signal status updated...'); 
        end
        end
        
        if(sigstatEv==1)
        url = 'http://tms.rahuldhole.com/SendData%20To%20file%20on%20server/led.php';
        fullURL = strcat(url, '?state=', 'se');
        str = 0;
        set(handles.text27,'String','Uploadiding east signal status'); 
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
        camINTRNv = a.digitalRead(CamINTRN);
        camINTRWv = a.digitalRead(CamINTRW);
        camINTRSv = a.digitalRead(CamINTRS);
        camINTREv = a.digitalRead(CamINTRE);
        %%
		%%in while
        %%Capture and upload
        if(camINTRNv==1 && sigstatNv == 0)  
            handles.emptyN = 0;
            guidata(hObject, handles);
            set(handles.text27,'String','Signal break: North'); 
            if(handles.cam1)
                im = getsnapshot(vidN);
                set(handles.text27,'String','Signal break: North>Image Captured'); 
                rgbmap = ycbcr2rgb(im);
                dt = datestr(now,'yyyy-mmmm-dd HH:MM:SS.FFF AM');
                dt = strcat('North: ',dt);
                imwrite(rgbmap,dt);
                f = fopen(dt); 
                d = fread(f,Inf,'*uint8'); % Read in byte stream of file 
                str=0;
                str = urlreadpost('http://tms.rahuldhole.com/imgdb/mat_img.php', ... 
                  {'image_name','North','datetime',dt,'file',d,'version','3','api_key','API-KEY','wait','Y'});
            end
        end
        
        
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
% hObject    handle to pushbutton26 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton27.
function pushbutton27_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton27 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton28.
function pushbutton28_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton28 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton29.
function pushbutton29_Callback(hObject, eventdata, handles)
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
