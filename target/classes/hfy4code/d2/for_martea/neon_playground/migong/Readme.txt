 ��װ˵��
�����뽫����Ϸ�ĵ� MASTER_OB �ڵ� compile_object()
�������ݸĳ�������ʽ��
mixed compile_object(string file)
{
        object daemon;
        if( daemon = find_object(VIRTUAL_D) )
                return daemon->compile_object(file);
        else
                return 0;
}
һ��� es2 �๹�ܵ���Ϸ��Ŷ�����ôд�ģ�VIRTUAL_D 
Ϊ "/adm/daemons/virtuald"������Ϸ�����û�д˶���
�����Լ������������Ϸ�� global include file �У�
һ��Ϊ "/include/globals.h"���� /adm/daemons/ �µ�
�����ļ�����������Ϸ����ӦĿ¼�£�vrm_server.c ��
������һЩע�͡�/d/try/ ��Ϊһ��20x20�Թ������ӣ�
vrm_help Ϊ�Թ������İ����ļ���
�����������Թ�������Դ����Ĺ������������ҹ�ͬѧ
      ϰ̽����ߵĳ��ԣ����˲��Դ��ṩ�κμ���֧�֡�
      ������Ա������޸ģ���û�з���ϣ���ܱ�������
      Ϸ�뱾���ߵ����֡��˴���ɸ�����Ҫ�����κ���
      ;������Ϸ�뱾����Ҳ�������д˴���ĺ������
      �����Ρ�
      ���ֺ�(Find)
               ������Ϸ MUD������
                      210.78.144.10 6666
