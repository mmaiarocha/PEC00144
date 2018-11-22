%============================================================================== 
  pkg load instrument-control
%==============================================================================
  clc;
  clear;
  close all;                                    % close all figures 

%==============================================================================
% 1. Configura aquisição
%------------------------------------------------------------------------------
  DT   = 32;                                    % acquision time per file (s)
  NT   = 1;                                     % number of acquisitions
  TT   = NT*DT;                                 % total acquisition time (s)
  dt   = 0.1;                                   % time step (larger than 0.1s)

  ii   = 1;                                     % acquisition sample number
  iT   = 1;                                     % acquisition number
  data = zeros(1,4);                            % first data line

  while iT <= NT,
%==============================================================================
% 2. Open serial port
%
%    Attention!!! At UBUNTU terminal...
%
%    "dmesg | grep tty"
%    "sudo chmod 666 /dev/ttyUSB0"
%
%------------------------------------------------------------------------------
  s = serial('/dev/ttyUSB0', 9600);
% s = serial('COM4',  9600);
  set(s, 'timeout', 20);
  pause(2);
  srl_flush(s);

%==============================================================================
% 3. Take mean values as sensors tare (only at beginning)
%------------------------------------------------------------------------------
  if (iT == 1),

      dat0 = zeros(1,3);

      for jj = 1:10,

          srl_write(s, 'r');     
          reading = srl_read(s,28);
          pause(dt);
          
         [c1, c2, c3] = strread(char(reading),'%d %d %d');
          dat0(1:3)   = dat0(1:3) + [c1 c2 c3];
          
      end
     
      dat0 = dat0/10.; 
    
      tic;
      t0   = toc;
      t    = toc - t0;
     
  end
  
%==============================================================================
% 3. Scan serial port 
%------------------------------------------------------------------------------
  figure(1);
 
  while (t - (iT - 1)*DT) <= DT,

     srl_write(s, 'r');               
     reading = srl_read(s,28);
     pause(dt);
     
    [c1, c2, c3]  = strread(char(reading),'%d %d %d');
     data(ii,2:4) = [c1 c2 c3] - dat0(1:3);

     t   =  toc - t0;
     data(ii,1) = t;
%    disp(data(ii,:));

     subplot(3,1,1);
     plot(t, 1*data(ii,2)/2^24,'k.'); 
     axis([0 TT -.1 .1]);
     hold on;
     grid on;
     
     subplot(3,1,2);
     plot(t, 1*data(ii,3)/2^24,'b.');
     axis([0 TT -.1 .1]);
     hold on;
     grid on;
     
     subplot(3,1,3);
     plot(t, 1*data(ii,4)/2^24,'r.');
     axis([0 TT -.1 .1]);
     hold on;
     grid on;
     
     drawnow;
     ii = ii + 1;
  end
  
  fclose(s);
  clear s

%==============================================================================
% 4. Save data
%------------------------------------------------------------------------------
  
  filename  = sprintf('LoadCell_%s.txt', datestr(now, 30));
  dlmwrite(filename, data(:,1:4),'delimiter', '\t','newline','pc');
  disp(['Closing file... ' filename]);
  
  printname = sprintf('ShearTest_%s.png', datestr(now, 30));  
  print('-dpng', printname);

  iT = iT + 1;

  end
  hold off;

%==============================================================================
% 6. End script file
%------------------------------------------------------------------------------
  return
