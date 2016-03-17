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
			System.out.println("�����                                      : 0");
	        System.out.println("�������� ��� ������                        : 1");
	        System.out.println("�������� ���� ����������                   : 2");
	        System.out.println("�������� ��� �����                         : 3");
	        System.out.println("�������� ��� ������������ �������� ���� �� : 4");
	        System.out.println("�������� ��� �����                         : 5");
	        System.out.println("�������� ����� ��������������              : 6");
	        System.out.println("�������� ������������ �����                : 7");
	        System.out.println("�������� ����� �� �����������              : 8");
	        System.out.println("�������� ���� ��� ����.�� ���� ��������.   : 9");
	        System.out.println("�������� ���� ��� ����.�� ���� ��������.   : 10");
	        System.out.println("��������� ��������� �� ����                : 11");
	        System.out.println("��������� ����� �� ����                    : 12");
	        System.out.println("��������� ����                             : 13");
	        System.out.println("������� ����                               : 14");
	        System.out.println("��������� ���������� � ��������� ����      : 15");
	        System.out.println("��������� ����� � ��������� ����           : 16");
	        System.out.println("�������� �����                             : 17");
	        System.out.println("������                                     : 18");
	        System.out.println("��������� ��� ����.                        : 19");
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
                 System.out.println("������� ID ���������:");
     	         nCargo = sc.nextInt();
                 System.out.println("������� ID �����:");
      	         nTrips = sc.nextInt();
      	         if (!((nCargo<0)&&(nTrips<0)))
           	     pTO.getAlternateForPassByTransp(nCargo,nTrips);
            break;   
            case 10:
                 System.out.println("������� ID �����:");
    	         nCargo = sc.nextInt();
                 System.out.println("������� ID �����:");
     	         nTrips = sc.nextInt();
     	         if (!((nCargo<0)&&(nTrips<0)))
          	     pTO.getAlternateForCargByTransp(nCargo,nTrips);
            break;
            case 11:
                 System.out.println("������� ID ���������:");
   	             nCargo = sc.nextInt();
            	 System.out.println("������� ID ����� ��� �������� ����������:");
    	         nTrips = sc.nextInt();
    	         if (!((nCargo<0)&&(nTrips<0)))
         	     pTO.loadPass(nCargo,nTrips);
            break;
            case 12:
                 System.out.println("������� ID �����:");
   	             nCargo = sc.nextInt();
           	     System.out.println("������� ID ����� ��� �������� �����:");
   	             nTrips = sc.nextInt();
   	             if (nTrips>=0)
        	     pTO.loadCargo(nCargo,nTrips);
            break;
            case 13:
            	 System.out.println("������� ID ����� ��� ��������:");
  	             nTrips = sc.nextInt();
  	             if (nTrips>=0)
           	     pTO.depTrips(nTrips);
            break;
            case 14:
           	     System.out.println("������� ID ����� ��� ������:");
	             nTrips = sc.nextInt();
	             if (nTrips>=0)
       	         pTO.arrTrips(nTrips);
            break;
            case 15:
          	     System.out.println("������� ID ����� ������������������ �������� ����������:");
	             nTrips = sc.nextInt();
	             if (nTrips>=0)
          	     pTO.loadAllPassAndGo(nTrips);
            break;
            case 16:
         	     System.out.println("������� ID ����� ������������������ �������� ������:");
	             nTrips = sc.nextInt();
	             if (nTrips>=0)
         	     pTO.loadAllCargoAndGo(nTrips);
            break;
            case 17:
            	 //int nX,nY,nIsAir,nIsAut,nIsTra,nIsWat;
            	 pTO.addCity("NewCity",100,390,1,0,1,1);
            	 /*
           	     System.out.println("������� �������� ������:");
	             strName = sc.next();
	             System.out.println("������� ���������� X:");
	             nX = sc.nextInt();
	             System.out.println("������� ���������� Y:");
	             nY = sc.nextInt();
	             System.out.println("������� ���� ������? 0-��� 1-��");
	             nIsAir = sc.nextInt();
	             System.out.println("������� ���� ������? 0-��� 1-��");
	             nIsAut = sc.nextInt();
	             System.out.println("������� ��   ������? 0-��� 1-��");
	             nIsTra = sc.nextInt();
	             System.out.println("������� ���� ������? 0-��� 1-��");
	             nIsWat = sc.nextInt();
         	     pTO.addCity(strName,nX,nY,nIsAir,nIsAut,nIsTra,nIsWat);
         	     */
            break;
	        }
		       }catch(Exception e){
		    	   System.out.println("CMain::>��������! ������� ������������ ����������.��������� ����.");
		    	   sc = new Scanner(System.in);//return;
		       }
	        if ((res==0))
	        {
	        	System.out.println("������ ���������� ���������.");
	        	return;
	        }
	       }
		pCL.close();
	}

}
