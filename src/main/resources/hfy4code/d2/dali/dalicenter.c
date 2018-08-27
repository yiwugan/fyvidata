//lmd@wenxin
inherit ROOM;
void create()
{
        set("short", "´óÀí³ÇÖĞĞÄ");
        set("long", @LONG
ÕâÀï¾ÍÊÇ´óÀí³ÇµÄ³ÇÖĞĞÄ£¬´óÀí³ÇµÄÖ÷Òª½ÖµÀ¶¼ÔÚÕâÀï½»»á£¬¿í¹ãµÄÂ·ÃæÔÚÕâÀï
ĞÎ³ÉÁËÒ»¸ö·½Ô°Ô¼Ê®ÓàÕÉµÄ¹ã³¡¡£¹ã³¡³ÊÁâĞÎ£¬Ò»È¦Î§µÄ¶¼ÊÇĞ¡··£¬ÒÕÈË£¬ºÍ¿´ÈÈÄÖ
µÄ¡£ÎõÎõÈÁÈÁµÄÈËÈºÖĞÒ²ÉÙ²»ÁËĞ©¸öÅÜ½­ºşµÄ£¬ÔÓË£Éù£¬½ĞÂôÉù´ËÆğ±Ë·ü¡£Ò»Ğ©ÔÚÖĞ
Ô­ÎÅËùÎ´ÎÅµÄĞÂÏÊÊÂÎïÁîÒ»Ğ©³õÈë½­ºşµÄÄêÇáÈËĞË·Ü²»ÒÑ¡£Î»ÓÚ¹ã³¡ÖĞĞÄÓĞÒ»¸ö²»´ó
²»Ğ¡µÄË®³Ø£¬Ò»¾Ş´óµÄÄÖÁúÊ¯ÖùËÊÁ¢Ë®³ØÖĞÑë£¬Ò»ãéãéµÄ¸ÊÈªË®´ÓÊ¯ÖùµÄÁú×ìÖĞÓ¿³ö£¬
·ÅÑÛÏòÊ¯ÖùÉÏ¿´È¥£¬Ö»¼ûÉÏÊé£º
[1;32m
                         ~   Ìì  ´ó  ~

                         ~   ÏÂ  Àí  ~

                         ~   Ì«  ÖĞ  ~

                         ~   Æ½  ĞË  ~
[37m                         

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gnroad1",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"eroad1",
  "west" : __DIR__"wroad1",
]));
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);
        set("outdoors", "dali");
        set("resource/water",1);
        set("liquid/name","Çå³ºµÄ³ØË®");
        set("liquid/type", "alcohol");
        set("liquid/drunk_apply",3);
        set("coor/x",-800);
        set("coor/y",-750);
        set("coor/z",80);
        setup();
// To "load" the board, don't ever "clone" a bulletin board.
  //      call_other( "/obj/board/dali_a", "???" );

}

void init()
{
        add_action("do_fillwater", "fillwater");
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "¸ÊÈªË®",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("ÄãÔÚÁú×ìÏÂ×°ÂúÁËÇå³ºµÄ¸ÊÈªË®£¡ \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("ÄãÃ»ÓĞ×°Ë®µÄ¶«Î÷°¡....\n");
                        return 1;
                }
        }
        else {
                write("ÄãÒªÍùÊ²Ã´¶«Î÷Àï¹àË®£¿\n");
        }
        return 1;
}