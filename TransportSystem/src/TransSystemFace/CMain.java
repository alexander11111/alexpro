package TransSystemFace;

import java.util.Scanner;

import PTableOrder.CTableOrders;

public class CMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CTableOrders pTO;
		CConfigLoader pCL = new CConfigLoader("jdbc:h2:tcp://localhost/~/test","sa","","org.h2.Driver");
		pTO = pCL.getSystem();
		Scanner sc = new Scanner(System.in);
		//CLoginFace lFace = new CLoginFace();
		int res=1;
		while(res!=0)
	       {
			System.out.println("Выход                                      : 0");
	        System.out.println("Показать все города                        : 1");
	        System.out.println("Показать всех пассажиров                   : 2");
	        System.out.println("Показать все грузы                         : 3");
	        System.out.println("Показать все транспортные средства всех ТК : 4");
	        System.out.println("Показать все рейсы                         : 5");
	        System.out.println("Показать рейсы грузоперевозок              : 6");
	        System.out.println("Показать пассажирские рейсы                : 7");
	        System.out.println("Показать рейсы по направлению              : 8");
	        System.out.println("Показать альт для пасс.по всем перевозч.   : 9");
	        System.out.println("Показать альт для груз.по всем перевозч.   : 10");
	        System.out.println("Загрузить пасажиров на рейс                : 11");
	        System.out.println("Загрузить грузы на рейс                    : 12");
	        System.out.println("Отправить рейс                             : 13");
	        System.out.println("Принять рейс                               : 14");
	        System.out.println("Загрузить пассажиров и отправить рейс      : 15");
	        System.out.println("Загрузить грузы и отправить рейс           : 16");
	        System.out.println("Добавить город                             : 17");
	        System.out.println("ОТМЕНА                                     : 18");
	        System.out.println("Загрузить поу молч.                        : 19");
	        try{
	        res = sc.nextInt();
	        int nCargo;
	        int nTrips;
	        String strName;
	        int nX,nY,nIsAir,nIsAut,nIsTra,nIsWat;
	        
	        switch(res){
            case 1:
            	 pTO.getCityTBL(-1);
            break;	 	            
            case 2:
            	 pTO.getPassTBL(-1);
            break;
            case 3:
           	     pTO.getCargoTBL(-1);
            break;	
            case 4:
           	     pTO.getTransportTBL(-1);
            break;	 
            case 5:
            	 pTO.getTripsTBL(-1,-1);
            break;	 	            
            case 6:
            	 pTO.getTripsTBL(0,-1);
            break;	 	            
            case 7:
            	 pTO.getTripsTBL(1,-1);
            break;	 	            
            case 8:
            	 pTO.getTripsByDir(1,0,3);
            break;            
            case 9:
                 System.out.println("Введите ID пассажира:");
     	         nCargo = sc.nextInt();
                 System.out.println("Введите ID Рейса:");
      	         nTrips = sc.nextInt();
      	         if (!((nCargo<0)&&(nTrips<0)))
           	     pTO.getAlternateForPassByTransp(nCargo,nTrips);
            break;   
            case 10:
                 System.out.println("Введите ID Груза:");
    	         nCargo = sc.nextInt();
                 System.out.println("Введите ID Рейса:");
     	         nTrips = sc.nextInt();
     	         if (!((nCargo<0)&&(nTrips<0)))
          	     pTO.getAlternateForCargByTransp(nCargo,nTrips);
            break;
            case 11:
                 System.out.println("Введите ID Пассажира:");
   	             nCargo = sc.nextInt();
            	 System.out.println("Введите ID Рейса для погрузки пассажиров:");
    	         nTrips = sc.nextInt();
    	         if (!((nCargo<0)&&(nTrips<0)))
         	     pTO.loadPass(nCargo,nTrips);
            break;
            case 12:
                 System.out.println("Введите ID Груза:");
   	             nCargo = sc.nextInt();
           	     System.out.println("Введите ID Рейса для погрузки груза:");
   	             nTrips = sc.nextInt();
   	             if (nTrips>=0)
        	     pTO.loadCargo(nCargo,nTrips);
            break;
            case 13:
            	 System.out.println("Введите ID Рейса для отправки:");
  	             nTrips = sc.nextInt();
  	             if (nTrips>=0)
           	     pTO.depTrips(nTrips);
            break;
            case 14:
           	     System.out.println("Введите ID Рейса для приема:");
	             nTrips = sc.nextInt();
	             if (nTrips>=0)
       	         pTO.arrTrips(nTrips);
            break;
            case 15:
          	     System.out.println("Введите ID Рейса автоматизированной погрузки пассажиров:");
	             nTrips = sc.nextInt();
	             if (nTrips>=0)
          	     pTO.loadAllPassAndGo(nTrips);
            break;
            case 16:
         	     System.out.println("Введите ID Рейса автоматизированной погрузки грузов:");
	             nTrips = sc.nextInt();
	             if (nTrips>=0)
         	     pTO.loadAllCargoAndGo(nTrips);
            break;
            case 17:
            	 //int nX,nY,nIsAir,nIsAut,nIsTra,nIsWat;
            	 pTO.addCity("NewCity",100,390,1,0,1,1);
            	 /*
           	     System.out.println("Введите Название города:");
	             strName = sc.next();
	             System.out.println("Введите координату X:");
	             nX = sc.nextInt();
	             System.out.println("Введите координату Y:");
	             nY = sc.nextInt();
	             System.out.println("Введите Аэро Вокзал? 0-нет 1-да");
	             nIsAir = sc.nextInt();
	             System.out.println("Введите Авто Вокзал? 0-нет 1-да");
	             nIsAut = sc.nextInt();
	             System.out.println("Введите ЖД   Вокзал? 0-нет 1-да");
	             nIsTra = sc.nextInt();
	             System.out.println("Введите Водн Вокзал? 0-нет 1-да");
	             nIsWat = sc.nextInt();
         	     pTO.addCity(strName,nX,nY,nIsAir,nIsAut,nIsTra,nIsWat);
         	     */
            break;
	        }
		       }catch(Exception e){
		    	   System.out.println("CMain::>Внимание! Введена недопустимая комбинация.Повторите ввод.");
		    	   sc = new Scanner(System.in);//return;
		       }
	        if ((res==0))
	        {
	        	System.out.println("Работа приложения закончена.");
	        	return;
	        }
	       }
		pCL.close();
	}

}
