#include <QTextStream>
#include <QString>
#include <fstream>
using namespace std;

int main()
{
	char * humor = "Your future depends on your dream.So go to sleep.\n"
				   "�������������δ��������˯��ȥ�ɡ�";
	QString qs = QString::fromLocal8Bit( humor );

	QByteArray data = qs.toUtf8();
	ofstream of("utf8.txt", ios::binary );
	of.write( data.data(), data.length() );
}