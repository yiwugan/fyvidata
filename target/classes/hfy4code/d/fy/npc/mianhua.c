 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("�ϰ���", ({ "boss" }) );
        set("gender", "Ů��" );
        set("age", 52);
        set("long",
                "�ϰ����Ƴ����·������������·����ι̶��Ҳ��ѿ���\n");
        set("combat_exp", 50);
        set("str",20);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/armor/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_bu","bu");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "�ϰ���Ц������λ" + RANK_D->query_respect(ob)
                                + "�������������������Ҫ��һ���ˡ�\n");
                        break;
                case 1:
                        say( "�ϰ���˵������λ" + RANK_D->query_respect(ob)
                                + "��������������˿����ˣ�����һ�°ɡ�\n");
                        break;
   }
} 
int  do_bu(string arg)
{
        object me, ob;
        int cost = 1;
        int gold;
        int i,j,base,current;
        string id,name ;        
        string file,newfile,filestring;
        me=this_player();
        id = me->query("id");
        gold = me->query("deposit")/10000;
        if( !arg ) return notify_fail("��Ҫ��ʲ�����\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("������û������������\n");
        if (j>=15) 
        return notify_fail("�ϰ���ҡ��ҡͷ˵����ƾ�ҵ��������Ѿ��޷��ٰ����޲���������ˣ���\n");
        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");
        if( !ob->query("armor_prop") )
        return notify_fail("��ֻ�ܲ��������ϵĶ�����\n");
        if( ob->query("equipped") )
        return notify_fail("�㲻�ɲ������ŵ����\n");
        if( !ob->query("owner") )
        return notify_fail("��ֻ�ɲ��Լ��������\n");
        base= (int)ob->query("base_armor");
        seteuid(ROOT_UID);
        current = (int) ob->query("armor_prop/armor");
        if(!ob->query("ji_times")) {
        	j=1;
        } else{
                j = ob->query("ji_times");
                }
 /*       for(j=1;j<=100;j++)
        {
                base = base + j;
                if(base >= current) break;
        }  */
        for(i=1; i<= j;i++)
                        cost = cost * 2;
        tell_object(me, WHT"��β��·��õ���������"+chinese_number(cost)+"���ƽ��´ν��õ���"+chinese_number(2*cost)+"���ƽ������ء�\n"+"�������ﻹ��"+chinese_number(gold)+"���ƽ�.\n"NOR);
        if( gold < cost)
           return  notify_fail("�����������" + sprintf("%d",cost)+ "�����ӡ�\n");
        me->add("deposit", -cost*10000);
        me->save();
        me->start_busy(1);
        ob->add("armor_prop/armor",j);
        ob->add("base_armor",j);
        ob->set("weight",(int)ob->query("weight")+j*50);
        ob->add("ji_times", 1);
        ob->save();
        ob->restore();
        if(ob->move(me))        
        message_vision("$N������"+ob->name()+"��˵�������ˣ�\n",this_object());
        seteuid(getuid());
        return 1;
}     
