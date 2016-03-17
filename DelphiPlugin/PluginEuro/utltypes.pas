unit utltypes;

interface
uses
    Windows,classes,comctrls;

const
//��������� �������
     CMD_ENABLED  = $8000;
     CMD_QWRCMPL  = $4000;
//����� ���� ������
  MTM_ENABLE                   = $00000001;
  DYM_ENABLE                   = $00000001;
//��������� ��������/��������
  SA_LOCK                      = 00;
  SA_UNLK                      = 01;
  SA_ALOK                      = 02;
  SA_CVRY                      = 03;
  SA_ALRM                      = 04;
  SA_REDY                      = 05;
  SA_HDUC                      = 06;
//��� ���������
  SD_ABONT                     = 0;
  SD_PRIMT                     = 1;
  SD_GROUP                     = 2;
  SD_VMETR                     = 3;
  SD_VPARM                     = 4;
  SD_REPRT                     = 5;
  SD_EVENS                     = 6;
  SD_LIMIT                     = 7;
  SD_REGIN                     = 8;
  SD_CLUST                     = 9;
//��������� ������ ��� ������� ��������
  PD_CURRT                     = 0;
  PD_ARCHV                     = 1;
  PD_GRAPH                     = 2;
  PD_PERIO                     = 3;
  PD_RPRTS                     = 4;
  PD_EVENS                     = 5;
  PD_LIMIT                     = 6;
  PD_VMETR                     = 7;
  PD_CHNDG                     = 8;
  PD_VECDG                     = 9;
  PD_CTRLF                     = 10;
  PD_MONIT                     = 11;
  PD_QWERY                     = 12;
  PD_CLUST                     = 13;
  PD_SCHEM                     = 14;
  PD_UNKNW                     = $ffff;
type
   PTTreeView    = ^TTreeView;
   TBooleanArray = array[0..32767] of Boolean;
   PBooleanArray = ^TBooleanArray;


    CTreeIndex = packed record
     PTIM     : Word;    //��������
     PTSD     : Word;    //���� ���� ��������� ������
     PNID     : Word;    //���� ���� ��������� ������
     PRID     : Word;    //������
     PAID     : Word;    //�������
     PGID     : Word;    //������
     PVID     : Word;    //����������� �������
     PCID     : Word;    //�������
     PPID     : Word;    //����
     PMID     : Word;    //��� �������
     PTID     : Word;    //�����
     PSID     : Word;    //��� ��������
     PDID     : Word;    //��� �����������
     PKey     : Word;
     FKey     : Word;
     PIID     : Integer;
     PSTT     : Byte;
     PTND     : TTreeView; 
    End;
    PCTreeIndex =^ CTreeIndex;
    CGDataSource = packed record
     {
     PKey       : Integer;
     FKey       : Integer;
     FParam     : Integer;
     FParam1    : Integer;
     FParam2    : Integer;
     FParam3    : Integer;
     FParam4    : Integer;
     }
     trTRI      : CTreeIndex;
     trPTND     : Pointer;
     strCaption : String;
     strClassName : String;
     dtTime0    : TDateTime;
     dtTime1    : TDateTime;
     nViewID    : Integer;
     nHeight    : Integer;
     nWidth     : Integer;
     pOwner     : TComponent;
    End;
    PCGDataSource =^ CGDataSource;
    CCData = packed record
     m_swID         : Integer;
     m_swVMID       : Integer;
     m_swCMDID      : Integer;
     m_swTID        : Integer;
     m_sTime        : TDateTime;
     m_byOutState   : Byte;
     m_byInState    : Byte;
     m_sfKI         : Double;
     m_sfKU         : Double;
     m_sbyMaskRead  : int64;
     m_sbyMaskReRead:Byte;
     m_sbyPrecision : Byte;
     m_sfValue      : Double;
     m_CRC          : Integer;
    End;
    PCData=^ CCData;
    CCDatas = packed record
     Count : Integer;
     Items : array of CCData;
    End;
    PCCDatas =^ CCDatas;
    SQWERYMDL = packed record
     m_snID         : Integer;
     m_snCLID       : Integer;
     m_snAID        : Integer;
     m_snSRVID      : Integer;
     m_snVMID       : Integer;
     m_snMID        : Integer;
     m_snPID        : Integer;
     m_snCLSID      : Integer;
     m_strCMDCluster: String[70];
     m_sAscueName   : String[100];
     m_sDBConnection: String[200];
     m_sdtBegin     : TDateTime;
     m_sdtEnd       : TDateTime;
     m_sdtPeriod    : TDateTime;
     m_swDayMask    : Word;
     m_sdwMonthMask : Dword;
     m_sbyEnable    : Byte;
     m_sbyPause     : Byte;
     m_sbyFindData  : Byte;
     m_snDeepFind   : Byte;
     m_nSrvWarning  : Integer;
     m_nAmChannel   : Integer;
     m_sbyState     : Byte;
     m_lChann       : TList;
     //Commands  : CCOMMANDS;
    End;
    PSQWERYMDL =^ SQWERYMDL;
    SQWERYMDLS=packed record
     Count : Integer;
     Items : array of SQWERYMDL;
    End;
    //������� ���������� �����������
    SL3PARAMS = packed record
     m_swID          : Integer;
     m_swAID         : WORD;
     m_swGID         : WORD;
     m_swVMID        : WORD;
     m_swParamID     : WORD;
     m_sParamExpress : String[250];
     m_sParam        : String[10];
     m_fValueSv      : Double;
     m_fValue        : Double;
     m_fMin          : Double;
     m_fMax          : Double;
     m_fLimit        : Double;
     m_fDiffer       : Double;
     m_dtLastTime    : TDateTime;
     m_stSvPeriod    : Integer;
     //m_byOutState    : Byte;
     //m_byInState     : Byte;
     m_sblTarif      : Byte;
     m_sblCalculate  : Byte;
     m_sblSaved      : Byte;
     m_sblEnable     : Byte;
     m_swStatus      : Byte;
     m_sbyDataGroup  : Byte;
     m_sbyRecursive  : Byte;
     m_sbyLockState  : Byte;
     m_snDataType    : Byte;
    end;
    PSL3PARAMS =^ SL3PARAMS;
    SL3PARAMSS = packed record
     Count : Integer;
     Items : array of SL3PARAMS;
    End;
    SL3VMETERTAG = packed record
     m_swID          : Word;
     m_swMID         : WORD;
     m_sbyPortID     : WORD;
     m_sbyType       : WORD;
     m_sbyGroupID    : Integer;
     m_swVMID        : WORD;
     m_swAmParams    : WORD;
     m_sbyExport     : Byte;
     m_sbyEnable     : Byte;
     m_sddPHAddres   : string[30];
     m_sMeterName    : String[150];
     m_sVMeterName   : String[150];
     m_swPLID        : integer;
     M_SMETERCODE    : string[30];
     //ItemCh          : SL3CHANDGES;
     Item            : SL3PARAMSS;
     ItemCD          : CCDatas;
    end;
    PSL3VMETERTAG =^ SL3VMETERTAG;
    SL3VMETERTAGS = packed record
     Count : Integer;
     Items : array of SL3VMETERTAG;
    End;
    //������� ������ ������������
    SL3GROUPTAG = packed record
     m_sbyID         : Integer;
     m_swABOID       : Integer;
     m_sbyGroupID    : Integer;
     m_swPLID        : Integer;
     m_swAmVMeter    : Integer;
     m_swPosition    : Integer;
     M_NGROUPLV      : Byte;
     m_nTarifMask    : DWord;
     m_sbyEnable     : Byte;
     m_sGroupName    : String[250];
     m_sGroupExpress : String[250];
     Item            : SL3VMETERTAGS;
    end;
    PSL3GROUPTAG =^ SL3GROUPTAG;
    //������� ������������� L3
    SL3INITTAG = packed record
     m_sbyLayerID    : Byte;
     Count           : Word;
     Items           : array of SL3GROUPTAG;
    end;
     //������� ��������
    SL3ABON = packed record
     m_swID      : Integer;
     m_swABOID   : Integer;
     m_swPortID  : Integer;
     m_sdtRegDate: TDateTime;
     m_nRegionID : Integer;
     m_sName     : string[100];
     m_sObject   : string[100];
     m_sKSP      : string[5];
     m_sDogNum   : string[25];
     m_sPhone    : string[25];
     m_sAddress  : string[75];
     m_sEAddress : string[55];
     m_sShemaPath: string[55];
     m_sComment  : string[200];
     m_sTelRing  : string[25];
     m_sRevPhone : string[35];
     m_sPhoto    : string;
     m_sbyEnable : Byte;
     m_sbyVisible: Byte;
     m_sReportVS : Int64;
     m_sLIC      : string[100];
     m_strOBJCODE: string[100];
     m_sMaxPower : double;
     m_sTreeSettings : int64;
     m_sAddrSettings : int64;//M_SADDRSETTINGS
     M_NABONTYPE     : Integer;
     M_SMARSHNUMBER  : string[10];
     M_SHOUSENUMBER  : string[5];
     M_SKORPUSNUMBER : string[5];
     Item        : SL3INITTAG;
     ItemVM      : SL3VMETERTAGS;
     //����� ����������������
    End;
    PSL3ABON =^ SL3ABON;
    SL3ABONS = packed record
     Count     : Integer;
     Items     : array of SL3ABON;
    end;
    PSL3ABONS =^ SL3ABONS;
    SL3USPDS = packed record
     //Count     : Integer;
     m_nSID    : Integer;
     m_sName   : String;
     m_nAbons  : SL3ABONS;
    end;
    PSL3USPDS = ^SL3USPDS;
    SCHANN = packed record
     m_nScID : Integer;
     m_nAsID : Integer;
     m_sfValue : double;
    End;
    PSCHANN = ^SCHANN;

    SCHANNS = packed record
     Count : Integer;
     Items : array of SCHANN;
    end;
    PSCHANNS = ^SCHANNS;

    SCHANNELS = packed record
     m_nSID  : Integer;
     m_sName : String;
     Items   : TList;
    end;

implementation
end.
 