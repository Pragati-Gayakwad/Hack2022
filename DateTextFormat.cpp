import java.util.Date;
import java.text.DateFormat;
import java.util.Locale;

class  Date_Formatting
{
	public static void main(String[] args) 
	{ 
Date obj1=new Date();

DateFormat df=DateFormat.getDateInstance();
String str1=df.format(obj1);

df=DateFormat.getDateInstance(DateFormat.DEFAULT,Locale.UK);
String str2=df.format(obj1);

df=DateFormat.getDateInstance(DateFormat.SHORT,Locale.UK);
String str3=df.format(obj1);


		System.out.println(str1);
		System.out.println(str2);
		System.out.println(str3);
	}
}
