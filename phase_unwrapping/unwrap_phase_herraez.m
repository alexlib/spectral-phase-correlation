function [PHASE_PLANE_UNWRAPPED] = unwrap_phase_herraez(PHASE_ANGLE_PLANE_WRAPPED)

% Size of the complex plane
[m,n]=size(PHASE_ANGLE_PLANE_WRAPPED);

% Convert complex plane to phase angle plane
PHASE_PLANE_UNWRAPPED = PHASE_ANGLE_PLANE_WRAPPED;

H=zeros(m-2,n-2);V=zeros(m-2,n-2);D1=zeros(m-2,n-2);D2=zeros(m-2,n-2);
%CALCULATING SECOND DIFFERENCE

for i=2:m-1
    for j=2:n-1
        H(i-1,j-1)=un2(PHASE_PLANE_UNWRAPPED(i-1,j)-PHASE_PLANE_UNWRAPPED(i,j))-un2(PHASE_PLANE_UNWRAPPED(i,j)-PHASE_PLANE_UNWRAPPED(i+1,j));
        V(i-1,j-1)=un2(PHASE_PLANE_UNWRAPPED(i,j-1)-PHASE_PLANE_UNWRAPPED(i,j))-un2(PHASE_PLANE_UNWRAPPED(i,j)-PHASE_PLANE_UNWRAPPED(i,j+1));
        D1(i-1,j-1)=un2(PHASE_PLANE_UNWRAPPED(i-1,j-1)-PHASE_PLANE_UNWRAPPED(i,j))-un2(PHASE_PLANE_UNWRAPPED(i,j)-PHASE_PLANE_UNWRAPPED(i+1,j+1));
        D2(i-1,j-1)=un2(PHASE_PLANE_UNWRAPPED(i-1,j+1)-PHASE_PLANE_UNWRAPPED(i,j))-un2(PHASE_PLANE_UNWRAPPED(i,j)-PHASE_PLANE_UNWRAPPED(i+1,j-1));
        
        %keyboard;
    end
end

%keyboard;
D=(H.^2 + V.^2 + D1.^2 + D2.^2).^(0.5);
%
%RELIABILITY MATRIX
Rl=1./D;Rl(Rl==inf)=0;

sx=2*(m-2)-1;sy=n-2;
%figure;surf(Rl);shading interp;  
% ALLOCATING EDGE VALUES AND SORTING THE UNWRAPPING PATH

Redge=zeros(sx,sy);

for p=1:sx
    for q=1:sy
        if floor(p/2)<p/2
            l=(p+1)/2;
            if q<= sy-1
                Redge(p,q)=Rl(l,q+1)+Rl(l,q);
            end
        elseif floor(p/2)==p/2
            Redge(p,q)=Rl(p/2,q)+Rl(p/2+1,q);
        end
    end
end

%keyboard;
vc=reshape(Redge,sx*sy,1);[cox,coy]=meshgrid(1:sx,1:sy);p1=reshape(cox',sx*sy,1);q1=reshape(coy',sx*sy,1);
[svc,In]=sort(vc,'descend');p1=p1(In);q1=q1(In);
svc(svc==0)=[];

%MAIN ALGORITHM 
group=zeros(m,n);count=1;
for k=1:length(svc)
    sti=p1(k);stj=q1(k);
    %keyboard;
    if floor(sti/2)<(sti/2)
        p=(sti+1)/2;q=stj;val1=PHASE_PLANE_UNWRAPPED(p+1,q+1);val2=PHASE_PLANE_UNWRAPPED(p+1,q+2);
        
                
            if group(p+1,q+1)==0 && group(p+1,q+2)==0
                group(p+1,q+1)=count;group(p+1,q+2)=count;
                [ph1,ph2]=un(val1,val2);
                PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;PHASE_PLANE_UNWRAPPED(p+1,q+2)=ph2;
                count=count+1;
                
            elseif group(p+1,q+1)~=0 && group(p+1,q+2)==0
                group(p+1,q+2)=group(p+1,q+1);
                [ph1,ph2]=un(val1,val2);
                PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;PHASE_PLANE_UNWRAPPED(p+1,q+2)=ph2;
                
            elseif group(p+1,q+1)==0 && group(p+1,q+2)~=0
                group(p+1,q+1)=group(p+1,q+2);
                [ph2,ph1]=un(val2,val1);
                PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;PHASE_PLANE_UNWRAPPED(p+1,q+2)=ph2;3;
                
            elseif group(p+1,q+1)~=0 && group(p+1,q+2)~=0 && group(p+1,q+1)~=group(p+1,q+2)   
                [r1,c1]=find(group==group(p+1,q+1));px=r1;py=c1;gcnt1=length(r1);
                [r2,c2]=find(group==group(p+1,q+2));qx=r2;qy=c2;gcnt2=length(r2);

                if gcnt1>gcnt2
                    
                    v2org=val2;
                    [ph1,ph2]=un(val1,val2);
                    PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;%phi(p+1,q+2)=ph2;
                    diffad=ph2-v2org;
                    idq=qx+(qy-1).*size(PHASE_PLANE_UNWRAPPED,1);
                    PHASE_PLANE_UNWRAPPED(idq)=PHASE_PLANE_UNWRAPPED(idq)+diffad;
                    group(idq)=group(p+1,q+1);
                elseif gcnt2>gcnt1
                    v1org=val1;
                    [ph2,ph1]=un(val2,val1);
                    %phi(p+1,q+1)=ph1;
                    PHASE_PLANE_UNWRAPPED(p+1,q+2)=ph2;
                    diffad=ph1-v1org;
                    idp=px+(py-1).*size(PHASE_PLANE_UNWRAPPED,1);
                     PHASE_PLANE_UNWRAPPED(idp)=PHASE_PLANE_UNWRAPPED(idp)+diffad;
                    group(idp)=group(p+1,q+2);
                elseif gcnt1==gcnt2
                    if group(p+1,q+1)< group(p+1,q+2)
                        v2org=val2;
                    [ph1,ph2]=un(val1,val2);
                    PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;%phi(p+1,q+2)=ph2;
                    diffad=ph2-v2org;
                    idq=qx+(qy-1).*size(PHASE_PLANE_UNWRAPPED,1);
                    PHASE_PLANE_UNWRAPPED(idq)=PHASE_PLANE_UNWRAPPED(idq)+diffad;
                    group(idq)=group(p+1,q+1);
                    elseif group(p+1,q+1)> group(p+1,q+2)
                     v1org=val1;
                    [ph2,ph1]=un(val2,val1);
                    %phi(p+1,q+1)=ph1;
                    PHASE_PLANE_UNWRAPPED(p+1,q+2)=ph2;
                    diffad=ph1-v1org;
                    idp=px+(py-1).*size(PHASE_PLANE_UNWRAPPED,1);
                     PHASE_PLANE_UNWRAPPED(idp)=PHASE_PLANE_UNWRAPPED(idp)+diffad;
                    group(idp)=group(p+1,q+2);
                    end
                end
            elseif  group(p+1,q+1)==group(p+1,q+2) && group(p+1,q+1)~=0 && group(p+1,q+2)~=0 
%                 [ph1 ph2]=un(val1,val2);
%                 phi(p+1,q+2)=ph2;
%                 if abs(val1-val2)>pi
%                     keyboard;
%                 end
                 continue;

            end
           
    elseif floor(sti/2)==sti/2
        p=sti/2;q=stj;val1=PHASE_PLANE_UNWRAPPED(p+1,q+1);val2=PHASE_PLANE_UNWRAPPED(p+2,q+1);
        
        if group(p+1,q+1)==0 && group(p+2,q+1)==0
                group(p+1,q+1)=count;group(p+2,q+1)=count;
                [ph1,ph2]=un(val1,val2);
                PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;PHASE_PLANE_UNWRAPPED(p+2,q+1)=ph2;
                count=count+1;
                
            elseif group(p+1,q+1)~=0 && group(p+2,q+1)==0
                group(p+2,q+1)=group(p+1,q+1);
                [ph1,ph2]=un(val1,val2);
                PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;PHASE_PLANE_UNWRAPPED(p+2,q+1)=ph2;
                
            elseif group(p+1,q+1)==0 && group(p+2,q+1)~=0
                group(p+1,q+1)=group(p+2,q+1);
                [ph2,ph1]=un(val2,val1);
                PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;PHASE_PLANE_UNWRAPPED(p+2,q+1)=ph2;
                
            elseif group(p+1,q+1)~=0 && group(p+2,q+1)~=0 && group(p+1,q+1)~=group(p+2,q+1)  
                [r1,c1]=find(group==group(p+1,q+1));px=r1;py=c1;gcnt1=length(r1);
                [r2,c2]=find(group==group(p+2,q+1));qx=r2;qy=c2;gcnt2=length(r2);

                if gcnt1>gcnt2
                    
                    v2org=val2;
                    [ph1,ph2]=un(val1,val2);
                    PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;%phi(p+1,q+2)=ph2;
                    diffad=ph2-v2org;
                   % 'loop starts'
                    idq=qx+(qy-1).*size(PHASE_PLANE_UNWRAPPED,1);
                    PHASE_PLANE_UNWRAPPED(idq)=PHASE_PLANE_UNWRAPPED(idq)+diffad;
                    group(idq)=group(p+1,q+1);
                   % 'loop ends'
                elseif gcnt2>gcnt1
                    v1org=val1;
                    [ph2,ph1]=un(val2,val1);
                    %phi(p+1,q+1)=ph1;
                    PHASE_PLANE_UNWRAPPED(p+2,q+1)=ph2;
                    diffad=ph1-v1org;
                    idp=px+(py-1).*size(PHASE_PLANE_UNWRAPPED,1);
                     PHASE_PLANE_UNWRAPPED(idp)=PHASE_PLANE_UNWRAPPED(idp)+diffad;
                    group(idp)=group(p+2,q+1);
                elseif gcnt1==gcnt2
                    if group(p+1,q+1)< group(p+2,q+1)
                         v2org=val2;
                    [ph1,ph2]=un(val1,val2);
                    PHASE_PLANE_UNWRAPPED(p+1,q+1)=ph1;%phi(p+1,q+2)=ph2;
                    3;
                    diffad=ph2-v2org;
                   % 'loop starts'
                    idq=qx+(qy-1).*size(PHASE_PLANE_UNWRAPPED,1);
                    PHASE_PLANE_UNWRAPPED(idq)=PHASE_PLANE_UNWRAPPED(idq)+diffad;
                    group(idq)=group(p+1,q+1);
                    elseif group(p+1,q+1)> group(p+2,q+1)
                        v1org=val1;
                    [ph2,ph1]=un(val2,val1);
                    %phi(p+1,q+1)=ph1;
                    PHASE_PLANE_UNWRAPPED(p+2,q+1)=ph2;
                    4;
                    diffad=ph1-v1org;
                    idp=px+(py-1).*size(PHASE_PLANE_UNWRAPPED,1);
                     PHASE_PLANE_UNWRAPPED(idp)=PHASE_PLANE_UNWRAPPED(idp)+diffad;
                    group(idp)=group(p+2,q+1);
                    end
                end
            elseif group(p+1,q+1)==group(p+2,q+1) && group(p+1,q+1)~=0 && group(p+2,q+1)~=0 
%                     [ph1 ph2]=un(val1,val2);
%                     phi(p+2,q+1)=ph2;
%                     if abs(val1-val2)>=pi
%                         keyboard;
%                     end
                 continue;
        end
         
     end

end

  
   %BOUNDARY VALUE UNWRAPPING
   for i=2:m-1
       %if j==1
           [~,ph1]=un(PHASE_PLANE_UNWRAPPED(i,2),PHASE_PLANE_UNWRAPPED(i,1));
           PHASE_PLANE_UNWRAPPED(i,1)=ph1;
       %elseif j==n
           [~,ph2]=un(PHASE_PLANE_UNWRAPPED(i,n-1),PHASE_PLANE_UNWRAPPED(i,n));
           PHASE_PLANE_UNWRAPPED(i,n)=ph2;
     % keyboard;
       %end
   end
   for j=1:n
       %if i==1
           [~,ph1]=un(PHASE_PLANE_UNWRAPPED(2,j),PHASE_PLANE_UNWRAPPED(1,j));
           PHASE_PLANE_UNWRAPPED(1,j)=ph1;
       %elseif i==m
           [~,ph2]=un(PHASE_PLANE_UNWRAPPED(m-1,j),PHASE_PLANE_UNWRAPPED(m,j));
           PHASE_PLANE_UNWRAPPED(m,j)=ph2;
       %end
   end
  
end

function [diff2]= un2(b)
mult=1;%abs(a-b)/(2*pi);
if (b)>pi
    b=b-2*pi*mult;
elseif (b)<=-pi
    b=b+2*pi*mult;
end
diff2=b;
end

function [ph1,ph2]= un(a,b)

 tol=pi;
 mul=2*(1+floor((abs(a-b)-pi)/(2*pi)));

if (b-a)>tol
    b=b-1*pi*mul;
elseif (b-a)<-tol
    b=b+1*pi*mul;
end

ph1=a;ph2=b;

end

%FINAL UNWRAPPED PHASE PLOT  
% figure(12);
% surf(phi,'FaceColor','interp', 'EdgeColor','none', 'FaceLighting','phong')
% view(-30,30), camlight left, axis tight
% xlabel('Pixels'), ylabel('Pixels'), zlabel('Phase in radians')
% title('Unwrapped phase using Miguels algorithm');
    
        