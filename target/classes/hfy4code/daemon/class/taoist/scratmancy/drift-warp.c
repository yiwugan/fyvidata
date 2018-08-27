 // earth-warp.c
#include <ansi.h>
#include <command.h>
#include <login.h> 
inherit F_CLEAN_UP; 
int scribe(object me, object sheet, string arg)
{
         string err;
         int extra;
         
        if(me->query("class")!="taoist")
                return notify_fail("ֻ�����幬���Ӳſ��Ի�����\n"); 
        if(me->query("have_mission"))
                return notify_fail("������֯�����������ܻ�����\n");  
        if(me->query("mission_over"))
                return notify_fail("��ֻ�����������ɵ���֯������ȡ������\n");        
        if((int)me->query_skill("scratmancy",1) < 58)
                return notify_fail("��ķ�֮�������ߣ�\n"); 
        if( sheet->name() != "�ҷ�ֽ" )
                return notify_fail("�����Ҫ�����ҷ�ֽ�ϣ�\n");
        
        if( (int)me->query("mana") < 100 ) 
                return notify_fail("��ķ��������ˣ�\n");
        write("��Ҫ�ڷ���дʲô��");
        input_to( (: call_other, __FILE__, "select_target", me,sheet :)); 
        return 1;
} 
void select_target(object me, object sheet,string name)
{
        object ob,newsheet;
        string fplace;
        
        if( !name || name=="" ) {
                write("��ֹд����\n");
                return;
        } 
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/item/magic_seal");
        newsheet->set_name(YEL "�����" NOR, 
                ({ "drift-warp sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->set("burn_person",me);
        newsheet->move(me);
        me->add("mana", -50);
        me->save();
        switch(name)    {
                case "taoguan":
                case "�������":
                        fplace="�������";
                        break;
                case "guanwai":
                case "������":
                        fplace="������";
                        break;
                case "chenghuang":
                case "�������":
                        fplace="�������";
                        break;
                case "songgu":
                case "�ɹ���":
                        fplace="�ɹ���";
                        break;
                case "daimiao":
                case "���":
                        fplace="���";
                        break;
                case "bat":
                case "����":
                        fplace="����";
                        break;
                case "xinjiang":
                case "�½�":
                	fplace="�½�";
                	break;
                case "baiyun":
                case "���Ƶ�":
                	fplace="���Ƶ�";
                	break;
                case "changchun":
                case "������":
                	fplace="������";
                	break;
        }
        
        if(stringp(fplace))
        {
                newsheet->set("long","һ�ŵ��ҵĶ������������׭��д��"+fplace+"�����֡�\n");
                newsheet->set("flying_place",fplace);
        }
        else newsheet->set("long","һ�ŵ��ҵĶ������\n");
        message_vision("$Nд��һ���������\n" NOR, me);
                
        return ;
} 
int do_warp(object sheet)
{
        object env, me;
        string fplace;
        me=this_player();
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty"))
                return notify_fail("�˵ز���ʹ�ö������\n");  
        me->start_busy(2+random(2));
        fplace=(string)sheet->query("flying_place");
        env = environment(me);
        message("vision",me->name()+WHT"��̤������������һ�Ŷ������ \n"NOR, env,me);
        message("vision",YEL "ƽ��ӿ��һ����ã������"+me->name()+YEL"����Ӱ��û��������... \n"NOR,env,me);
        if(sheet->query("burn_person")==this_player())
                call_out("move_him",1+random(4),this_player(),fplace);
        else
                message_vision("���ʲô��û�з�����\n",this_player());
        return 1;
}
int move_him(object me,string fplace)
{
        string place;           
        message("vision", "WHT ��������ɢȥ��$N�Ѿ���ʧ����Ӱ���١�  \n"NOR
                ,me,({me}));
        message("vision",
                MAG "��Χ�ľ�ɫ��ɰ������ȥ���㲻���е�ͷ��Ŀѣ�� \n"
YEL "��е���Χ�ľ�ɫ�����������������Ѿ���������һ���ط��� \n"NOR, me);
        switch(fplace) {
                case "�������":
                        place="/d/taoguan/da_dian";
                        break;
                case "������":
                        place="/d/guanwai/templeyard";
                        break;
                case "�ɹ���":
                        place="/d/huangshan/songgu";
                        break;
                case "���":
                        place="/d/daimiao/tongting";
                        break;
                case "�������":
                        place="/d/fy/hiretem";
                   	break;
                case "����":
                        place="/d/bat/jueding";
                        break;
                case "�½�":
                	place="/d/xinjiang/qianfo";
                	break;
                case "���Ƶ�":
                	place="/d/baiyun/baiyunentrance";
                	break;
                case "������":
                	place="/d/tieflag/rock0";
                	break;                	
        }
        if(!stringp(place))
                place="/d/taoguan/da_dian";
        me->move(place);
        message("vision",YEL "����Χ��Ȼ����һ��ַ磬"+me->name()+"����Ӱ�ƺ��ӷ���������������ǰ�� \n"NOR,
                place, ({me}) );
      
        return 1;
        
}
   
