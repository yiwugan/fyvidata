 // abandon.c
#include <ansi.h>
inherit F_CLEAN_UP;
void abandon_skill(string confirm, object me, string skill);
int zero_skill(object me, string arg); 
int main(object me, string arg)
{
        string err;
        if( !arg || arg=="" ) return notify_fail("��Ҫ������һ��ܣ�\n"); 
        //if(!find_object(SKILL_D(arg)) && !load_object(SKILL_D(arg))) {
        if(!find_object(SKILL_D(arg)) && file_size(SKILL_D(arg)+".c")<0) {
                return notify_fail("��" + arg + "���������ּ�����\n");        
        }
        /*if(!load_object(SKILL_D(arg)+".c")) 
                return notify_fail("��" + arg + "���������ּ�����\n");
        */      
        seteuid(getuid());
        err = catch( call_other(SKILL_D(arg)+".c", "???") );
        if (err)
                printf( "��������\n%s\n", err );
                 
        if( !me->query_skill(arg,1) && !zero_skill(me,arg))
                return notify_fail("�㲢û��ѧ������ܡ�\n");
        write(HIY"\n����������ָ������ܴ��������������ɾ����������Ժ�Ҫ����\n������㿪ʼ����������ؿ��������\n"NOR);
        write("�������������ѧϰ��"HIR + SKILL_D(arg)->name() + NOR"�ݣ��Ƿ�Ҫ������(yes/no)\n");
        input_to( (: abandon_skill :), me, arg);
        return 1;
} 
void abandon_skill(string confirm, object me, string skill) 
{
        if (! (confirm == "yes" || confirm == "YES")) 
                write("�����һ���亹�����գ�\n");
        else    {
                if(me->query_skill(skill,1)>50)
                log_file("skills/ABANDON",
                  sprintf("%s(%s)��%s������%d��%s��\n",
                  me->name(1),geteuid(me),ctime(time()),me->query_skill(skill,1),skill));
                me->delete_skill(skill);
                write("�������������ѧϰ" + SKILL_D(skill)->name() + "��\n");
        }
}  
int zero_skill(object me, string arg) {
        mapping learned_skill_points;
        
        learned_skill_points=me->query_learned();
        if (!learned_skill_points[arg]) return 0;
        return 1;
}  
        
        
         
int help()
{
        write(@TEXT
ָ���ʽ��abandon <��������> 
����һ������ѧ�ļ��ܣ�ע��������˵�ġ���������ָ������ܴ��������������
ɾ������������ỹҪ��������� 0 ��ʼ����������ؿ�������� 
���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�������Ǽ�����
��������ʱ������������ĸ��ֶ�����ս����ѧϰ�������Щ���ܻ���Ϊ�㾭����ʹ
�ö���������ļ����б��У��������ͱ��뻨��һЩ����ȥ����ס����ѧ����һ��
��Ȼ�����˵����ʸ��в�ͬ�����Ըߵ����ܹ�ѧϰ��༼�ܶ���Ϊ��Ŷ��յĲ��ӣ�
���Խϲ���˾�ֻ��ר����ض�����ܣ������ѧ�ļ�������̫�࣬�����������
����ᷢ�������ѧϰ�ٶȽ���ֻѧ���ּ��ܵ�����������Խ�࣬ѧϰЧ���������
��Խ���أ��������ξ�����һ��ѧ��ͬʱѡ��̫��ѧ�֣���Ȼ����Ȼ����ƾ�����˵�
��־������ȥ�������⽫��໨������౦���ʱ�䡣
TEXT
        );
        return 1;
}       
