// ce.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

        void create() {seteuid(getuid());}

int main(object me, string arg)
{
      object obj;

      if(!me->query("marry")) return help(me);

        obj = find_player(me->query("marry"));

        if(!obj)
                return notify_fail("你的伴侣现在不在呢....\n");

        if( !arg ){
        message_vision(HIM "\n$N多么思念"+obj->query("name")+"啊...\n"NOR, me);

 tell_object(obj,sprintf(HIM"你的"+obj->query("name")+"在思念你... ...\n" NOR));
                }
      else {
          write(HIM "你悄悄告诉你的" + obj->query("name") + "：" + arg + "\n" NOR);
          tell_object(obj, sprintf( HIM "你的%s悄悄告诉你：%s\n" NOR,
                  me->query("name"), arg)); }

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：ce [<讯息>]

你可以用这个指令对你的伴侣说悄悄话。

HELP
        );
        return 1;
}
