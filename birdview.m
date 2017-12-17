% Created on 1/6/2013
% Written by Xuesong Li in Wuhan University of Technonlogy(http://www.whut.edu.cn/)
% Descrption: this is a tiny part of bachelor thesis (Vehicle 360 Degree Panoramic Display System)
%

%%
clear;
clc;
% getting the four input image
P1=qian(); % front image
P2=zuo(); % left image
P3=you(); % right image
P4=hou(); % back image
P5=imread('5.jpg');
H6 = 1650;
W6 = 1100;
V6 = 3;
%% creating full view image
Image_6 = zeros ( H6 , W6 ,V6 );
%Image = zeros ( height , width ,v );
Image_6  = uint8 ( Image_6  );%È¡Õû
for i_6 = 1:W6 
  for j_6 = 1:H6
      if i_6 <= 350
          if j_6 <= 255
            Image_6(j_6,i_6,:) = P1(j_6,i_6,:); 
          else
              if j_6 <= 1300
            Image_6(j_6,i_6,:) = P2(i_6,1301-j_6,:);
              else
            Image_6(j_6,i_6,:) = P4(1651-j_6,1101-i_6,:); 
              end
          end
      else
          if  i_6 <=750
              if j_6 <= 350
               Image_6(j_6,i_6,:) = P1(j_6,i_6,:);  
              else
                  if( j_6 <=1300)
                Image_6(j_6,i_6,:) = P5(j_6-350,i_6-350,:);
                  else
                 Image_6(j_6,i_6,:) = P4(1651-j_6,1101-i_6,:) ;    
                 
                 end
              end
          else
             if(j_6 <=1298) %1300)
               Image_6(j_6,i_6,:)= P3(1101-i_6,j_6,:);   
             else
               if(j_6 <=1300)
              Image_6(j_6,i_6,:) = P3(1101-i_6,1298,:);    
               else
              Image_6(j_6,i_6,:) = P4(1651-j_6,1101-i_6,:) ;                 
                end
             end
          end
      end
      
  end
end
figure, imshow (Image_6) ;