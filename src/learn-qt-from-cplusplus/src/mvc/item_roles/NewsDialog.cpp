#include "NewsDialog.h"

typedef struct {
	char * news_title, * image_filename;
	char * news_in_Chinese,  * news_in_English;
} News_Info;
		
News_Info news_2011[10] = {
	{"�ձ���Х", "images/Japan_Tsunami.jpg",
	"3��14�գ��ձ������ش���һ�Ҵ����嵽�ݶ������ܱ�������Ƭ��Χ��\n"
	"11�գ��ձ�������������8.9�������������µĺ�Х���ձ�����ͺ�Х\n"
	"���¸�����һ�˵�վ����й©�¹ʣ�����������й©���ܱߵ�����������\n"
	"1986���ж�ŵ�������¹�֮�������������صĺ����ѡ�",
	"A tsunami-tossed boat rests on top of a building amid a sea of debris in Otsuchi, Iwate Prefecture, on March 14 --days after a magnitude 8.9 earthquake struck off the northeastern coast of Japan, triggering adevastating tsunami.The Japan earthquake and tsunami also led to a crisis at the Fukushima Daiichi nuclear power plant, which leaked radioactive material into the surrounding region. The accident is now regarded as the largest nuclear disaster since the Chernobyl incident in 1986."},

	{"51��������ɻ�","images/spy_plane.jpg",
	"������50������ڣ����ص�����51������һ���Ѳ���A-12����ɻ�ԭ�ͻ�\n"
	"׼�������״���ԡ�����һϵ�н���֮���ڻ������51��������ս�ڼ�\n"
	"�����ϸ�����մ�������£����а���5�¹�����A-12����׹���Լ��й�\n"
	"�ڸ�׹���¹��������Ƭ����Щ��Ƭ��ǰ��δ���⹫�������״Ｘ���޷�\n"
	"̽�⵽A-12����ʱ�ٿɴﵽ2200Ӣ��(ÿСʱ3540����)��������70������\n"
	"���������½�����ּ���ɻ��ܹ���9��Ӣ��(2.74����)�ĸ߶����㵽����\n"
	"��ֻ��1Ӣ��(30����)�������塣���������ܼ���Ҳ���ɱ���ش������գ�\n"
	"1963�꣬һ��A-12����ɻ���51��������׹�١�",
	"Suspended upside down, a titanium A-12 spy-plane prototype is prepped for radar testing at Area 51 in the late 1950s.After a rash of declassifications, details of Cold War workings at the Nevada base, which to this day does not officially exist, are coming to light--including images of an A-12 crash and its cover-up pictured publicly for the first time in May.Nearly undetectable to radar, the A-12 could fly at 2,200 miles (3,540 kilometers) an hour--fast enough to cross the continental U.S. in 70 minutes. From 90,000 feet (27,400 meters),the plane's cameras could capture foot-long (0.3-meter-long) objects on the ground below. But pushing the limits came with risks--and led to the catastrophic 1963 crash of an A-12 based out of Area 51."},

	{"ī���纣�׵���","images/underwater_bodies.jpg",
	"2011��1�£���ī���翲�����������������Ƭչ����һ��ǱӾ�ߴ����˴�С\n"
	"�ĵ����Ϸ��ι��ľ�����Щ���˴�С�ĵ��ܳ���Ӣ�����ܼ�\n"
	"ղɭ���¿���˹��̩��֮�֣��������ڼ��ձȺ����ף�ռ�����\n"
	"����4520ƽ��Ӣ��(Լ��420ƽ����)���������һ�������б�ʾ��\n"
	"�����������Ϲ�ģ���ͬʱ��׳�۵�ˮ�¾���֮һ�������ں���\n"
	"��Ⱦ����ˮ�¶������Լ����Ȳ��̣�ī�����ɺ����������в��\n"
	"̩��ϣ��ˮ�µ����ܹ�ת���ο͵����ߣ������ǽ���Ȥ��ɺ����\n"
	"�Ƶ���Щ�������ϡ���ͳ�ƣ�ÿ���н�75���ο��������ص�ɺ������",
	"A snorkeler swims over life-size statues near Canc��n, Mexico, in a picture released in January.Created by Mexico-based British sculptor Jason deCaires Taylor, the Caribbean installation is intended to eventually cover more than 4,520 square feet (420 square meters),which would make it \"one of the largest and most ambitious underwater attractions in the world,\" according to a museum statement. In doing so, Taylor hopes Mexico's natural reefs, which are already stressed by marine pollution, warming waters, and overfishing, can catch a break from the approximately 750,000 tourists who visit the area each year."},

	{"��������","images/Shark.jpg",
	"10����ī���緢�ֵĺ�����������̥�������̥����22Ӣ��(56����)��\n"
	"ֻ��һֻ�۾�������ͷ��ǰ����������һ����Ϊ�����ۻ��Ρ��������Լ�����\n"
	"�ܶද�ﶼ����ֶ��ۻ��Σ������������ڡ��ܿ�ѷά������������ݴ�ѧ\n"
	"�о����������ѧ�Ҽ�ķ����������ر�ʾ����ѧ�Ҵ�ǰ������η���\n"
	"��������̥����������һֱδ����ĸ���Ⲷ��������㣬˵����������\n"
	"�޷���Ұ����ܾá�",
	"This extremely rare cyclops shark, found in Mexico, was confirmed by scientists in October. The 22-inch-long (56-centimeter-long) fetus has a single, functioning eye at the front of its head. The eye is a hallmark of a congenital condition called cyclopia, which occurs in several animal species, including humans.��Scientists have documented cyclops-shark embryos a few times before, said Jim Gelsleichter, a shark biologist at the University of North Florida in Jacksonville. The fact that none have been caught outside the wombsuggests cyclops sharks don't survive long in the wild."},

	{"�ձ����ֺ�ˮ","images/Japan_fire_flood.jpg",	
	"3��11�գ��ձ�����8.9�������Ϯ�����������º�Х�����ѷ�����\n"
	"�������ݱ����ں�ˮ�У��������ȼ�ա�����ʱ������2��46�֣�\n"
	"�����Ϯ����̨�غ�81Ӣ��(130����)�ĺ��򡣵��������ĺ�Х�漴\n"
	"Ϯ�������Լ100���˿ڵĸۿڳ��У����˸߶ȴﵽ33Ӣ��(10��)��\n"
	"�����ձ�140�������ܵ������𣬾������д�Լ250Ӣ��(400����)\n"
	"�Ķ���Ҳ�е���к�����",
	"Houses burn amid flood waters on March 11 after a magnitude 8.9 earthquake off the coast of Japan triggered a powerful tsunami��The earthquake--the strongest in Japan in 140 years--struck 81 miles (130 kilometers) off the coast of Sendai at 2:46 p.m. local time. A port city of about a million residents, Sendai was hit by tsunami waves up to 33 feet (10 meters) high.The earthquake and its aftershocks were felt as far away as Tokyo, about 250 miles (400 kilometers) from the epicenter��"},

	{"911ʮ�������","images/911.jpg",
	"��ŦԼ��һ���ֵ������ؾ���������������Ա����Ƭ��2001��9��11��\n"
	"�ֲ�Ϯ�������Ǿ����䲻����ŦԼ����9��11�����/����ݸ����ˡ�\n"
	"9��11������Ƭ���������ļ��䡷�༭�������¡�������ʾ���������Ҵ���\n"
	"������˵����������Ա���ϵı��飬���Ǿ�֪������ж��㣬���ǿ��ܳ�\n"
	"��ȥ�ˡ����������֪���Լ�������ʲô����Σ����ǰ�����Ǳ��ֳ�����\n"
	"�����������Ӣ��Ʒ�ʡ���",
	"People on a New York City street scan pictures of the many police and fire personnel still missing in the wake of the September 11, 2001, terrorist attacks.\"I've heard from any number of survivors that they could tell by looking at firefighters' faces [the firefighters] knew how bad this was and that they might not get out,\" said Clifford Chanin, an executive at New York City's National 9/11 Memorial and Museum and editor of Memory Remains, a photographic book of 9/11 artifacts. \"They knew what they were facing, and the heroism and courage [they showed] is just astonishing.\""},

	{"�������","images/fungus.jpg",
	"�������֣���ʬ���ϵ�ͷ�����ⳤ��һ�����ƾ��ɵ����壬��������ɡ�\n"
	"ʵ������һ���·��ֵ��������Ϊ��Ophiocordyceps camponoti-balzani����\n"
	"��ѧ��3�±�ʾ����������������Ϊ�ǵ�һ���֣���Ϊ��Ophiocordyceps \n"
	"unilateralis������ʵ������4����Ȼ��ͬ����Ⱥ������ȫ���ܹ�������\n"
	"���д��Լ�����Ophiocordyceps camponoti-balzani�ܹ���Ⱦ���ϲ�ռ��\n"
	"���ǵĴ��ԣ�һ�������ƶ������������������ʹ������ӵ��������Ǳ��\n"
	"ʹ��ɱ�֣�ɱ�����ϡ�",
	"A stalk of the new fungus species Ophiocordyceps camponoti-balzani grows out of a \"zombie\" ant's head in a Brazilian rain forest.Originally thought to be a single species, called Ophiocordyceps unilateralis, the fungus is actually four distinct species--all of which can \"mind control\" ants, scientists announced in March.The fungus can infect an ant, take over its brain, and then kill the insect once the it moves to an ideal location for growing and spreading the fungus's spores."},

	{"�����������","images/crocodile.jpg",
	"��������3�ܵ��Ѳ���һ������21Ӣ��(6.4��)����ˮ�������ڷ��ɱ�����������\n"
	"��Ա��9�±�ʾ�����������Ϊֹ����������������㡣����������\n"
	"2369��(1075����)��������ΪLolong�������Ϯ�����࣬���������������\n"
	"Ŀǰ��Lolong��ʱ�����������������ϵ�һ��Χ���ڡ�",
	"Caught alive after a three-week hunt, an allegedly 21-foot-long (6.4-meter-long) saltwater crocodile caught in the Philippines may be the largest crocodile yet captured, officials said in September.��The 2,369-pound (1,075-kilogram) crocodile is suspected of attacking several people and killing two. The animal, named Lolong, survived capture and was held in a temporary enclosure near Bunawan township (map)."},
			
	{"��������˹��","images/space_shuttle.jpg",	
	"2000��9��8�գ�����������˹���ź���ɻ���������������ݵĿ����\n"
	"�������ķ������ա��ڸ����Ŀɿɺ�̲�����ϵĳ��˰�����Ŀ����\n"
	"����������˹���ŷ��������ľ������������ҵ�����־���ı༭\n"
	"�������Ƭ��Ϊ������ֺ���ɻ��ƻ���������������Ƭ֮һ��\n"
	"7�£�����������˹�������STS-135����������ʱ30��ĺ���ɻ�\n"
	"�ƻ������һ��̫������STS-135����ָ�ӹٿ���˹�и�������ɭ\n"
	"�ڹ��ʿռ�վ���ܲɷ�ʱ˵��������ɻ��ǽ�30�������̫�շ��мƻ�\n"
	"�ĺ��ĺ���꣬�����������ۣ�������е�һ˿�˸С�",
	"Cocoa Beach surfers watch from the water as the space shuttle Atlantis lifts off from nearby Kennedy Space Center in Florida on September 8, 2000.The shot was among those chosen by National Geographic editors as the most unforgettable pictures from the entire NASA shuttle program.In July Atlantis completed STS-135, the final shuttle mission in the program's 30-year history.\" The space shuttle has been with us at the heart and soul of the human spaceflight program for about 30 years, and it's a little sad to see it go away,\" STS-135 mission commander Christopher Ferguson told reporters in a televised interview from the International Space Station."},

	{"�ͻ�˹̹������","images/web_wrapped_tree.jpg",
	"�ͻ�˹̹�ŵ�ʡ��һ�����䣬һƬ����ˮ��û��ũ��ߵ����ϳ���\n"
	"׳�۵�֩����������һ���޴�ļ롣Ϊ�˶�ܿ��µĺ�ˮ��������ֻ\n"
	"֩��--���ܻ�����������--�������Ͻ�����2010��7�£��ͻ�˹̹\n"
	"�ս����꣬�̶�һ���ڵĽ������㼸����ͬ�����10��Ľ�������\n"
	"���ºܶ�������ǡ����ź�ˮ������ȴ���ͻ�˹̹ũ��������־޴��ˮ�ӡ�",
	"Trees shrouded in ghostly cocoons line the edges of a submerged farm field in the Pakistani village of Sindh, where massive floods drove millions of spiders and possibly other insects into the trees to spin their webs.��Beginning last July, unprecedented monsoons dropped nearly ten years' worth of rainfall on Pakistan in one week, swelling the country's rivers. The water was slow to recede, creating vast pools of stagnant water across the countryside."}
};

NewsDialog::NewsDialog()
{
	listWidget = new QListWidget(this);
	listWidget->setViewMode(QListView::IconMode);
    listWidget->setIconSize(QSize(120, 80));
    listWidget->setMovement(QListView::Static);
	listWidget->setFixedWidth(340);
    listWidget->setSpacing(12);
    
	for ( int i=0; i<10; i++) {
		News_Info news = news_2011 [i];		
		QListWidgetItem * item = new QListWidgetItem(listWidget);
		item->setData(Qt::DisplayRole,		QObject::tr(news.news_title) );
		item->setData(Qt::DecorationRole,	QIcon(news.image_filename) );
		item->setData(Qt::TextAlignmentRole,Qt::AlignHCenter );		
		item->setData(Qt::ToolTipRole,		QString( QObject::tr(news.news_in_Chinese)) );
		item->setData(Qt::UserRole,			QString( news.news_in_English) );
	}
	connect(listWidget,
            SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
            this, SLOT(changeNews(QListWidgetItem *, QListWidgetItem*)));

	image = new QLabel(this);
	news  = new QLabel(this);
	news->setWordWrap( true );
	news->setFont( QFont("Times New Roman",16) );

	QVBoxLayout *right = new QVBoxLayout;
	right->addWidget(image);
	right->addWidget(news);
  
	QHBoxLayout * mainLayout = new QHBoxLayout;
    mainLayout->addWidget(listWidget);
    mainLayout->addLayout(right);
    setLayout(mainLayout);

    setWindowTitle(tr("2011 Top News"));
}

void NewsDialog::changeNews(QListWidgetItem *current, QListWidgetItem *previous)
{
	int row = listWidget->row( current );
	image->setPixmap( QPixmap( news_2011[row].image_filename ) );
	news->setText( current->data(Qt::UserRole).toString() );
}