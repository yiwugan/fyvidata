 // silencer@fy4 workgroup ������֮ľ��
inherit ROOM;  
void    setup_room_desc(object room,int length) {
        
        int x,y, exit_number;
        
        x=room->query("coor/x")/10;
        y=room->query("coor/y")/10;
        exit_number= sizeof(room->query("exits"));
        
        
        if ( x == length-1 || y == length-1 || x = 0 || y == 0) {
                room->set("pos","edge");
                room->set("short","���ֱ�Ե");                  //      Edge
                room->set("long",@LONG
�ƺ��ߵ������ӱ�Ե���ƺ���û�У������֦Ҷ����ï�ܣ�������������Ĵ�
���������ڽӹ�ľ��ɽޱ������Ľ��ܵ�ӵ���У���������������һ˿ϣ����
�ķ��飬�������Ļ�һƬ��û����⣬ֻ��һ�����ɵ����⣬���������ҵ�һ����
·�Ļ������ܾ���Զ���������ˡ�
LONG
        );
        } else  if (exit_number>2) {                            //      Crossroad
                room->set("pos","crossroad");
                room->set("short","����");
                room->set("long",@LONG
��һ�ŵ�һ�ŵ��ߵ������ǰ������һ��·�ڣ����ƺ�������������ƺ���û
�У����ܵ���ľ�м����˴˷��뿪������ʾ�ڳ���������·�һ�����ź�Ƿ����
�˵Ļ��ڣ�����谵�����ϡ�ɼ��Ķ�����Ҳ����һ����խ��С·��Ҳ��ֻ��һ
���ÿյ����ɣ��ݺύ���ɢ���ڻ��ߵĿ�֦�Ϳ�Ҷ�С�
LONG
        );
        } else  if (exit_number==1) {                           //      Deadend
                room->set("pos","deadend");
                switch (random(3)) {
                        case 0:         {                       
                room->set("short","���־���");
                room->set("long",@LONG
�����Ӿ����Ǹ��Թ����Իð��������ǰ���쿪������ľ��������������ǰ�
�ߺ����Ҷ����ǰ���������ɵ����⣬�ƺ��Ķ��������ߣ����ƺ��Ķ������ǳ�·��
û���������ߵ���һ������������ֻ���˻�ȥ��Ѱ��·�ˡ�
LONG
        );
        }
                        case 1: {
                room->set("short","����С��");
                room->set("long",@LONG
һЩ�����˵����ˣ�һ����Ҫ������ͤ�ӣ����������ﾹȻ������ס���ĺۼ���
С���Ѿ����ٻ���������ľ�Ľ����֦�ң���ʢ����չ�����ĺ��������Ҷ��֯
�ɵĲ�������ţ��Լ����ܳ����ľ��룬������ס��С�ݵ�ȫ����
LONG
        );
        }               
                        default:        {
                room->set("short","ʪ̿��");
                room->set("long",@LONG
ҶʢҶ�䣬�긴һ�꣬���������ط��Ŀ�Ҷ�Ѿ������а���ÿ���꼾��
�²��Ҷ�Ӿͻ��ڻ��������У�ʱ�䳤�ˣ��ڵͰ��ĵط����γ���������һ�����
�أ�һ��С�ĲȽ�ȥ�����ٰγ�������������ȫ���ݽ�ȥ�Ŀ��ܡ�
LONG
        );
        }                       
        }
        } else {                                                //      Normal description
                room->set("pos","normal");
                room->set("short","������");
                room->set("long",@LONG
�߽����֣�ͻȻ������ղŴ���ж������������Իð�������ǰ���쿪������
�����岽����ǰ����һƬ������һƬ���֣�ͻȻ�䣬ֻ����Ҷ��ɳɳ���죬ǰ����
���Ҷ�����ľ��һ����һ�����Ҷ�׷�Ʈ�䣬���������Ļ�һƬ��û����⣬ֻ
��һ�����ɵ����⡣�������ʱ��ͷ�Ļ���������Ҳ�߲���ȥ�ˡ�
LONG
        );
        }
}   
void    setup_npc_obj(object room){
                
        string *wood_npc;
        string *wood_obj;
        
        switch (room->query("short")) {
           case "����С��":        
                        room->set("objects",([
                                "/obj/money/thousand-cash" : 1,
                        ]));
                        break;
                case "���־���":
                        room->set("objects",([
                                __DIR__"npc/w-sentry-3": 1,
                        ]));
                        break;
                case "����":
                        room->set("objects",([
                                __DIR__"npc/w-sentry-2": 1,
                        ]));
                        break;
                case "���ֱ�Ե":
                        room->set("objects",([
                                "/obj/money/gold" : 1,
                        ]));
                        break;
                case "ʪ̿��":
                        room->set("objects",([
                                "/obj/money/tenthousand-cash" : 1,
                        ]));
                        break;  
                default :
                        room->set("objects",([
                                __DIR__"npc/w-sentry-1": 1,     
                        ]));
                        break;  
                
        }
        room->setup();
}      
