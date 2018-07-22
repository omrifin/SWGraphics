#include "../CheckList/CheckList.h"
#include "../Textbox/TextBox.h"
#include "../Control/EventEngine.h"
#include "../Label/Label.h"
#include "../Combox/Combox.h"
#include "../Panel/Panel.h"
#include "../Button/Button.h"
#include "../RadioList/RadioList.h"
#include "../NumericBox/NumericBox.h"
#include "../MessageBox/Messagebox.h"

auto MsgBox = [](Control* c){
	auto msg = dynamic_cast<Messagebox*>(c);
	msg->show();
};

int main(){
	Label lTitle(20);
	lTitle.setValue("Student");
	lTitle.setBorder(BorderType::Single);
	lTitle.setForeground(Color::Red);
	Label lName(10);
	lName.setValue("Name:");
	lName.setBorder(BorderType::Double);
	Label lAddress(10);
	lAddress.setValue("Address:");
	lAddress.setBorder(BorderType::Double);
	Label lCountry(18);
	lCountry.setValue("Country:");
	lCountry.setBorder(BorderType::Double);
	Label lSex(10);
	lSex.setValue("Gender:");
	lSex.setBorder(BorderType::Double);
	Label lInterests(10);
	lInterests.setValue("Interests:");
	lInterests.setBorder(BorderType::Double);
	Label lAge(15);
	lAge.setValue("Age:");
	lAge.setBorder(BorderType::Double);
	TextBox tName(30);
	tName.setValue("Johannes Von Mizrahi");
	tName.setBorder(BorderType::Double);
	TextBox tAddress(30);
	tAddress.setValue("Land down under, 24");
	tAddress.setBorder(BorderType::Double);
	Combox cCountry(18, { "'Straya", "Dibjouti", "Greenland" });
	cCountry.setSelectedIndex(1);
	cCountry.setBorder(BorderType::Double);
	RadioList rSex(2, 11, { "Dude", "Dudette" });
	rSex.setBorder(BorderType::Double);
	CheckList clInterests(3, 10, { "Potato", "Potato1", "Potato2" });
	clInterests.selectIndex(1);
	clInterests.selectIndex(2);
	auto v = clInterests.getSelectedIndices();
	cCountry.getSelectedIndex();
	clInterests.setBorder(BorderType::Double);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.setBorder(BorderType::Double);
	Button bSubmit(13);
	bSubmit.setValue("   Send");
	bSubmit.setBorder(BorderType::Double);
	Button bExit(13);
	bExit.setValue("    Exit");
	bExit.setBorder(BorderType::Double);
	Messagebox msg(10, 35);
	Panel main(26,75);
	main.setBackground(Color::Blue);
	main.setForeground(Color::White);
	main.setBorder(BorderType::Double);
	main.addControl(lTitle, (main.getWidth() - lTitle.getWidth()) / 2, 2);
	main.addControl(lName, 13, 6);
	main.addControl(lAddress, 13, 10);
	main.addControl(lCountry, 3, 14);
	main.addControl(lSex, 26, 14);
	main.addControl(lInterests, 41, 14);
	main.addControl(lAge, 57, 14);
	main.addControl(tName, 27, 6);
	main.addControl(tAddress, 27, 10);
	main.addControl(cCountry, 3, 18);
	main.addControl(rSex, 26, 18);
	main.addControl(clInterests, 41, 18);
	main.addControl(nAge, 57, 18);
	main.addControl(bSubmit, (main.getWidth()*1/4) , 24);
	main.addControl(bExit, (main.getWidth() * 3 / 5), 24);
	main.addControl(msg, (main.getWidth()-msg.getWidth())/2, 10);
	bSubmit.addListener(MsgBox, &msg);
	Control::setFocus(tName);
	auto eventEngine = EventEngine::getEngine();
	auto eStop = [&](Control* c) {eventEngine.stop(); };
	bExit.addListener(eStop, nullptr);
	eventEngine.run(main);
	return 0;
}