%% TCP/IP Sender

% Clear console and workspace
clc;
clear all;
close all;

% Configuration and connection
t = tcpip('localhost',8080);

% Open socket and wait before sending data
fopen(t);

clk = 0;
reset = 1;
fwrite(t,[clk, reset]);
solution=fread(t, 9);
clk = 1;
reset = 1;
fwrite(t,[clk, reset]);
solution=fread(t, 9);
clk = 0;
reset = 0;
fwrite(t,[clk, reset]);
solution=fread(t, 9);
count = 0;
best = solution;
while count ~= 4
    if clk == 0 
        clk = 1;
    else
        clk = 0;
    end
    fwrite(t,[clk, reset]);
    solution=fread(t, 9);
    if clk == 1
        display(transpose(solution));
        count = count + 1;
        if ~isequal(best, solution)
            best = solution;
            count = 0;
        end
    end
end
display(best);
fwrite(t,[2, reset]);


fclose(t);
delete(t);
