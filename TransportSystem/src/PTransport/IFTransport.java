package PTransport;

import PTransported.IFTransported;

public interface IFTransport {
      void departures();
      void arrival();
      boolean loadMan(IFTransported ifTd);
      boolean loadCargo(IFTransported ifTd);
      int getTransUnits(IFTransported ifTd);
	  String getName();
	  double getCost();
	  double getSpeed();
	  double getCargoCapacity();
	  int getPasgrCapacity();
	  String getTransInfo();
}
