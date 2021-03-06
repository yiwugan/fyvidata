 // silencer@fy4 workgroup 五行阵之木阵
inherit ROOM;  
void    setup_room_desc(object room,int length) {
        
        int x,y, exit_number;
        
        x=room->query("coor/x")/10;
        y=room->query("coor/y")/10;
        exit_number= sizeof(room->query("exits"));
        
        
        if ( x == length-1 || y == length-1 || x = 0 || y == 0) {
                room->set("pos","edge");
                room->set("short","密林边缘");                  //      Edge
                room->set("long",@LONG
似乎走到了林子边缘，似乎又没有，这儿的枝叶分外茂密，绿闪闪的蛇麻的丛
蔓，纠缠在接骨木，山薇，榛树的紧密的拥抱中，把你冲出密林最后的一丝希望绞
的粉碎，树林里幽昏一片。没有天光，只有一种蒙蒙的黯光，若不能另找到一条出
路的话，可能就永远困在这里了。
LONG
        );
        } else  if (exit_number>2) {                            //      Crossroad
                room->set("pos","crossroad");
                room->set("short","密林");
                room->set("long",@LONG
高一脚低一脚地走到这儿，前面又是一个路口，你似乎曾到过这儿，似乎又没
有，密密的树木有几处彼此分离开来，显示黑沉沉的深洞，仿佛一个打着呵欠的怕
人的虎口，在这昏暗的深处依稀可见的东西，也许是一条狭窄的小路，也许只是一
株烂空的树干，纵横交错地散乱在荒芜的枯枝和枯叶中。
LONG
        );
        } else  if (exit_number==1) {                           //      Deadend
                room->set("pos","deadend");
                switch (random(3)) {
                        case 0:         {                       
                room->set("short","密林绝径");
                room->set("long",@LONG
这林子就像是个迷宫，迷幻般地在你面前延伸开来，树木交错丛生，脚下是半
尺厚的落叶，眼前是迷迷蒙蒙的黯光，似乎哪儿都可以走，又似乎哪儿都不是出路。
没几步你又走到了一条绝径，看来只有退回去另寻出路了。
LONG
        );
        }
                        case 1: {
                room->set("short","无人小屋");
                room->set("long",@LONG
一些倒坏了的栏杆，一个快要倒掉的亭子，在这密林里竟然还有人住过的痕迹。
小屋已经大半毁坏倒塌，树木的交错的枝梢，繁盛地伸展开来的好象颤动的叶子织
成的不整的穹门，以及藤萝长长的卷须，几乎遮住了小屋的全部。
LONG
        );
        }               
                        default:        {
                room->set("short","湿炭地");
                room->set("long",@LONG
叶盛叶落，年复一年，树林里许多地方的枯叶已经积了有半尺深，每逢雨季，
下层的叶子就会融化在泥土中，时间长了，在低凹的地方就形成了象沼泽一般的泥
地，一不小心踩进去很难再拔出脚来，甚至有全部陷进去的可能。
LONG
        );
        }                       
        }
        } else {                                                //      Normal description
                room->set("pos","normal");
                room->set("short","密林中");
                room->set("long",@LONG
走进密林，突然明白你刚才错的有多厉害，林子迷幻般在你面前延伸开来，走
了四五步，眼前仍是一片树林又一片树林，突然间，只有落叶的沙沙声响，前、后、
左、右都是树木，一蓬又一蓬的落叶纷纷飘落，树林里是幽昏一片。没有天光，只
有一种蒙蒙的黯光。如果不及时回头的话，可能再也走不出去了。
LONG
        );
        }
}   
void    setup_npc_obj(object room){
                
        string *wood_npc;
        string *wood_obj;
        
        switch (room->query("short")) {
           case "无人小屋":        
                        room->set("objects",([
                                "/obj/money/thousand-cash" : 1,
                        ]));
                        break;
                case "密林绝径":
                        room->set("objects",([
                                __DIR__"npc/w-sentry-3": 1,
                        ]));
                        break;
                case "密林":
                        room->set("objects",([
                                __DIR__"npc/w-sentry-2": 1,
                        ]));
                        break;
                case "密林边缘":
                        room->set("objects",([
                                "/obj/money/gold" : 1,
                        ]));
                        break;
                case "湿炭地":
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
