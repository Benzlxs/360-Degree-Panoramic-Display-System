function P3 = you()
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
x1=load('X3.txt');
%x=load('matlab-X1.mat');
y1=load('Y3.txt');
Xf=x1;
Yf=y1;

rgb = imread('3.jpg');
% rgb=imread('3.jpg');
[ height, width, v2 ] = size(rgb);
%[X0,Y0,R] = Yuan(rgb); %����Բ�������Բ�����꼰�뾶
%figure,imshow(rgb)
%hold on
%R=load('H.txt');
%T=load('T.txt');
h1=350;
%w1=950;
w1=1300;
%h1=480;
%w1=260;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Image = zeros ( h1 , w1 ,v2 );
%Image = zeros ( height , width ,v );
Image = uint8 ( Image );%ȡ��
%Image(v0, u0, 1:3)=rgb(y0,x0,1:3);
%figure,imshow(Image)
hw=175;
%ww=475;
ww=650;
%figure,imshow(Image);
%hw=65;
%ww=40;
%ȡ����ƽ��ͼ��������һ��p��x,y��,x,y��Ϊ����
for y = 1:h1
    for x = 1:w1-1
    yw = (h1-y)*hw/h1;
    xw = x*ww/w1;
    sh = yw/25;
    zb = xw/25;
    sh_i = floor(sh);
    zb_j = floor(zb);
    %����Ҫ��ʾ��ͼ�񻮷ֳ�һ��һ���ķ������ĸ�����
    fg_1 = zb_j*8+1+sh_i;
    fg_2 = fg_1+1;
    fg_3 = fg_2+8;
    fg_4 = fg_1+8;
    u1_1= Xf(fg_1)-(Xf(fg_1)-Xf(fg_2))*(sh-sh_i);
    u1_2= Xf(fg_4)-(Xf(fg_4)-Xf(fg_3))*(sh-sh_i);
    u1  = u1_1 + (u1_2-u1_1)*(zb-zb_j);
    v1_1= Yf(fg_1)+(Yf(fg_2)-Yf(fg_1))*(sh-sh_i);
    v1_2= Yf(fg_4)+(Yf(fg_3)-Yf(fg_4))*(sh-sh_i);
    v1  = v1_1 + (v1_2-v1_1)*(zb-zb_j);
    i=floor(u1);   %x�������
    j=floor(v1);    %y�������
    a=u1-i; b=v1-j ; %��С������
    u= i ; 
    v= j; %(u,v)����ԭͼ���ж�Ӧ�������
    if  v > height || v < 1 || u > width || u < 1 ||v>height-1||u>width-1%�������ͼ��֮�����Ϣ��ȥ
           continue    
    end
    
    Image( y, x,:)=(1-a)*(1-b)*rgb( v, u,:)+a*(1-b)*rgb( v+1, u,:)+b*(1-a)*rgb( v, u+1,:)+a*b*rgb( v+1, u+1,:);
  
    end
end

%%%%%%��ֵ%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%CorrectionImage = imresize ( Image , [ 480 720 ] , 'bilinear' );
%figure ,imshow(CorrectionImage);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%figure, imshow ( Image) ;
P3= Image;

end

