 inherit ROOM;
void create()
{
  set("short","���ش��");
  set("long",@LONG
����һ�������������ֱ�����������������͵�������Ͽ�����
Լ�������Ƴǵĳ��ţ����ǼúӶɿڣ�������һƬ���֣�������һ��
ɽ��������ɽ���ؽ硣
LONG
  );
  set("exits",([
         "west" :AREA_LAOWU"road2",
         "east" :__DIR__"shanjiao",
         "north" : "/p/residence/room2",
               ])); 
        set("outdoors", "qianfo");
  set("coor/x",10);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
} 
