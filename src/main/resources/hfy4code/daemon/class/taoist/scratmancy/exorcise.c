 // earth-warp.c
#include <ansi.h>
#include <command.h>
#include <login.h> 
inherit F_CLEAN_UP; 
int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n");
   
        if((int)me->query_skill("scratmancy",1) < 100 )
                return notify_fail("��ķ�֮�������ߣ�\n"); 
        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("��ʦն���Ҫ�����ҷ�ֽ�ϣ�\n"); 
        if( (int)me->query("mana") < 200 ) 
                return notify_fail("��ķ��������ˣ�\n");
        if( me->query("sen")<300)
                return notify_fail("���������ǲ��Ǻ�������޷�������\n"); 
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/item/magic_seal");
        newsheet->set_name(YEL "��ʦն���" NOR, 
                ({ "exorcise sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->move(me);
        me->add("mana", -150);
//      me->receive_wound("sen", 50);
        me->save();
        message_vision("$Nд��һ����ʦն�����\n" NOR, me);
        return 1;
} 
int do_warp(object sheet)
{
        object me,weapon;
        int extra, exp_bonus;
        
        me=this_player();
        if(me->query("class")!="taoist")
           return notify_fail("ֻ�����幬���Ӳ��ܹ�����ʦն�����\n"); 
        weapon=me->query_temp("weapon");
        if(!weapon||!weapon->query("for_taoist"))
                return notify_fail("����ʦն�����������Ӧ�ķ�����ϲ��С�\n"); 
        if(me->query_skill_mapped("sword")!="snowshade-sword")
                return notify_fail("����ʦն���������ѩӰ��������ϡ�\n"); 
        extra=me->query_skill("snowshade-sword",1);
        if (extra<120)
                return notify_fail("��ѩӰ��������Ϊ����������޷�ʹ����ʦն�����\n");
        if(weapon->query("exorcising"))
                return notify_fail("��ѽ��Ѿ���ʩ�������ˡ�\n"); 
        me->start_busy(1);
        message_vision(BLU"$N����һ����ʦն������ֳ���ľ����ʹ��ѩӰ���������������дʡ�����\n",me);
        message_vision(HIW"$N������ľ������һָ���ѽ��������ڽ��⣡��\n\n",me);
        message_vision(HIR"��ֽ��תΪ��죬Ѫɫӳ�����ڳ�ÿ���˵����ϣ���\n"NOR,me);
        weapon->set("name","����һ�ŷ�ֽ����ľ��");
        exp_bonus = me->query_skill("scratmancy",1);
        extra = extra/4 + exp_bonus;
        extra = extra*4 + random(extra);
        weapon->set("exorcising",extra);
        call_out("remove_effect",exp_bonus,weapon);
        return 1;
}
int remove_effect(object weapon)
{
        object holder;
        
        if(!weapon)
                return 1;
        holder=environment(weapon);
        if(!holder)
                return 1;
        if(interactive(holder)) 
                message_vision(CYN"��ľ�����ϵķ�ֽתΪ��ɫ����������ɢ���ˡ�\n"NOR,holder);
        else    
                message("vision",CYN"��ľ�����ϵķ�ֽתΪ��ɫ����������ɢ���ˡ�\n"NOR,holder);
        weapon->delete("exorcising");
        weapon->set("name","��ľ��"); 
        return 1;
}
       
