object TFrmAscue: TTFrmAscue
  Left = 395
  Top = 213
  Width = 924
  Height = 631
  Caption = '����� ���������'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = OnCreateFrm
  PixelsPerInch = 96
  TextHeight = 13
  object AdvOfficeStatusBar1: TAdvOfficeStatusBar
    Left = 0
    Top = 578
    Width = 916
    Height = 19
    AnchorHint = False
    Panels = <
      item
        AppearanceStyle = psLight
        DateFormat = 'dd.MM.yyyy'
        Progress.BackGround = clNone
        Progress.Indication = piPercentage
        Progress.Min = 0
        Progress.Max = 100
        Progress.Position = 0
        Progress.Level0Color = clLime
        Progress.Level0ColorTo = 14811105
        Progress.Level1Color = clYellow
        Progress.Level1ColorTo = 13303807
        Progress.Level2Color = 5483007
        Progress.Level2ColorTo = 11064319
        Progress.Level3Color = clRed
        Progress.Level3ColorTo = 13290239
        Progress.Level1Perc = 70
        Progress.Level2Perc = 90
        Progress.BorderColor = clBlack
        Progress.ShowBorder = False
        Progress.Stacked = False
        Style = psText
        TimeFormat = 'h:mm:ss'
        Width = 780
      end
      item
        AppearanceStyle = psLight
        DateFormat = 'dd.MM.yyyy'
        Progress.BackGround = clNone
        Progress.Indication = piPercentage
        Progress.Min = 0
        Progress.Max = 100
        Progress.Position = 0
        Progress.Level0Color = clLime
        Progress.Level0ColorTo = 14811105
        Progress.Level1Color = clYellow
        Progress.Level1ColorTo = 13303807
        Progress.Level2Color = 5483007
        Progress.Level2ColorTo = 11064319
        Progress.Level3Color = clRed
        Progress.Level3ColorTo = 13290239
        Progress.Level1Perc = 70
        Progress.Level2Perc = 90
        Progress.BorderColor = clBlack
        Progress.ShowBorder = False
        Progress.Stacked = False
        Style = psTime
        Text = '13:06:03'
        TimeFormat = 'h:mm:ss'
        Width = 594
      end>
    SimplePanel = False
    URLColor = clBlue
    Styler = AdvOfficeStatusBarOfficeStyler1
    Version = '1.2.0.6'
  end
  object AdvPanel1: TAdvPanel
    Left = 0
    Top = 0
    Width = 916
    Height = 33
    Align = alTop
    BevelOuter = bvNone
    Color = 16640730
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    UseDockManager = True
    Visible = False
    Version = '1.7.9.0'
    BorderColor = clGray
    Caption.Color = 14059353
    Caption.ColorTo = 9648131
    Caption.Font.Charset = DEFAULT_CHARSET
    Caption.Font.Color = clWhite
    Caption.Font.Height = -11
    Caption.Font.Name = 'MS Sans Serif'
    Caption.Font.Style = []
    Caption.GradientDirection = gdVertical
    Caption.Indent = 2
    Caption.ShadeLight = 255
    CollapsColor = clHighlight
    CollapsDelay = 0
    ColorTo = 14986888
    ShadowColor = clBlack
    ShadowOffset = 0
    StatusBar.BorderColor = clNone
    StatusBar.BorderStyle = bsSingle
    StatusBar.Font.Charset = DEFAULT_CHARSET
    StatusBar.Font.Color = clWhite
    StatusBar.Font.Height = -11
    StatusBar.Font.Name = 'Tahoma'
    StatusBar.Font.Style = []
    StatusBar.Color = 14716773
    StatusBar.ColorTo = 16374724
    StatusBar.GradientDirection = gdVertical
    Styler = AdvPanelStyler1
    FullHeight = 0
    object AdvToolBar2: TAdvToolBar
      Left = 0
      Top = 0
      Width = 302
      Height = 31
      AllowFloating = True
      CaptionFont.Charset = DEFAULT_CHARSET
      CaptionFont.Color = clWindowText
      CaptionFont.Height = -11
      CaptionFont.Name = 'MS Sans Serif'
      CaptionFont.Style = []
      CompactImageIndex = -1
      TextAutoOptionMenu = 'Add or Remove Buttons'
      TextOptionMenu = 'Options'
      ToolBarStyler = AdvToolBarOfficeStyler1
      ParentStyler = False
      ParentOptionPicture = True
      ParentShowHint = False
      ToolBarIndex = -1
      object AdvGlowMenuButton2: TAdvGlowMenuButton
        Left = 9
        Top = 2
        Width = 143
        Height = 27
        Caption = '��������� �����������'
        FocusType = ftHot
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        TabOrder = 0
        OnClick = OnConnTblClick
        Appearance.BorderColor = 14727579
        Appearance.BorderColorHot = 10079963
        Appearance.BorderColorDown = 4548219
        Appearance.BorderColorChecked = 4548219
        Appearance.Color = 15653832
        Appearance.ColorTo = 16178633
        Appearance.ColorChecked = 11918331
        Appearance.ColorCheckedTo = 7915518
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 7778289
        Appearance.ColorDownTo = 4296947
        Appearance.ColorHot = 15465983
        Appearance.ColorHotTo = 11332863
        Appearance.ColorMirror = 15586496
        Appearance.ColorMirrorTo = 16245200
        Appearance.ColorMirrorHot = 5888767
        Appearance.ColorMirrorHotTo = 10807807
        Appearance.ColorMirrorDown = 946929
        Appearance.ColorMirrorDownTo = 5021693
        Appearance.ColorMirrorChecked = 10480637
        Appearance.ColorMirrorCheckedTo = 5682430
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        Appearance.GradientHot = ggVertical
        Appearance.GradientMirrorHot = ggVertical
        Appearance.GradientDown = ggVertical
        Appearance.GradientMirrorDown = ggVertical
        Appearance.GradientChecked = ggVertical
        DropDownButton = True
        DropDownMenu = AdvPopupMenuSys
      end
      object AdvGlowMenuButton3: TAdvGlowMenuButton
        Left = 152
        Top = 2
        Width = 136
        Height = 27
        Caption = '��������� �������'
        FocusType = ftHot
        NotesFont.Charset = DEFAULT_CHARSET
        NotesFont.Color = clWindowText
        NotesFont.Height = -11
        NotesFont.Name = 'Tahoma'
        NotesFont.Style = []
        TabOrder = 1
        OnClick = OnChannTblClick
        Appearance.BorderColor = 14727579
        Appearance.BorderColorHot = 10079963
        Appearance.BorderColorDown = 4548219
        Appearance.BorderColorChecked = 4548219
        Appearance.Color = 15653832
        Appearance.ColorTo = 16178633
        Appearance.ColorChecked = 11918331
        Appearance.ColorCheckedTo = 7915518
        Appearance.ColorDisabled = 15921906
        Appearance.ColorDisabledTo = 15921906
        Appearance.ColorDown = 7778289
        Appearance.ColorDownTo = 4296947
        Appearance.ColorHot = 15465983
        Appearance.ColorHotTo = 11332863
        Appearance.ColorMirror = 15586496
        Appearance.ColorMirrorTo = 16245200
        Appearance.ColorMirrorHot = 5888767
        Appearance.ColorMirrorHotTo = 10807807
        Appearance.ColorMirrorDown = 946929
        Appearance.ColorMirrorDownTo = 5021693
        Appearance.ColorMirrorChecked = 10480637
        Appearance.ColorMirrorCheckedTo = 5682430
        Appearance.ColorMirrorDisabled = 11974326
        Appearance.ColorMirrorDisabledTo = 15921906
        Appearance.GradientHot = ggVertical
        Appearance.GradientMirrorHot = ggVertical
        Appearance.GradientDown = ggVertical
        Appearance.GradientMirrorDown = ggVertical
        Appearance.GradientChecked = ggVertical
        DropDownButton = True
        DropDownMenu = AdvPopupMenuCount
      end
    end
  end
  object AdvPanel2: TAdvPanel
    Left = 0
    Top = 33
    Width = 916
    Height = 545
    Align = alClient
    BevelOuter = bvNone
    Color = 16640730
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    UseDockManager = True
    Version = '1.7.9.0'
    BorderColor = clGray
    Caption.Color = 14059353
    Caption.ColorTo = 9648131
    Caption.Font.Charset = DEFAULT_CHARSET
    Caption.Font.Color = clWhite
    Caption.Font.Height = -11
    Caption.Font.Name = 'MS Sans Serif'
    Caption.Font.Style = []
    Caption.GradientDirection = gdVertical
    Caption.Indent = 2
    Caption.ShadeLight = 255
    CollapsColor = clHighlight
    CollapsDelay = 0
    ColorTo = 14986888
    ShadowColor = clBlack
    ShadowOffset = 0
    StatusBar.BorderColor = clNone
    StatusBar.BorderStyle = bsSingle
    StatusBar.Font.Charset = DEFAULT_CHARSET
    StatusBar.Font.Color = clWhite
    StatusBar.Font.Height = -11
    StatusBar.Font.Name = 'Tahoma'
    StatusBar.Font.Style = []
    StatusBar.Color = 14716773
    StatusBar.ColorTo = 16374724
    StatusBar.GradientDirection = gdVertical
    Styler = AdvPanelStyler1
    FullHeight = 0
    object pgPager: TAdvOfficePager
      Left = 0
      Top = 0
      Width = 916
      Height = 545
      AdvOfficePagerStyler = AdvOfficePagerOfficeStyler1
      Align = alClient
      ActivePage = tcConnect
      ButtonSettings.CloseButtonPicture.Data = {
        424DA20400000000000036040000280000000900000009000000010008000000
        00006C000000C30E0000C30E00000001000000010000427B8400DEEFEF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0001000001010100000100
        0000000202000100020200000000000202020002020200000000010002020202
        0200010000000101000202020001010000000100020202020200010000000002
        0202000202020000000000020200010002020000000001000001010100000100
        0000}
      ButtonSettings.PageListButtonPicture.Data = {
        424DA20400000000000036040000280000000900000009000000010008000000
        00006C000000C30E0000C30E00000001000000010000427B8400DEEFEF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0001010101000101010100
        0000010101000200010101000000010100020202000101000000010002020202
        0200010000000002020200020202000000000002020001000202000000000100
        0001010100000100000001010101010101010100000001010101010101010100
        0000}
      ButtonSettings.ScrollButtonPrevPicture.Data = {
        424DA20400000000000036040000280000000900000009000000010008000000
        00006C000000C30E0000C30E00000001000000010000427B8400DEEFEF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0001010101000001010100
        0000010101000202000101000000010100020202000101000000010002020200
        0101010000000002020200010101010000000100020202000101010000000101
        0002020200010100000001010100020200010100000001010101000001010100
        0000}
      ButtonSettings.ScrollButtonNextPicture.Data = {
        424DA20400000000000036040000280000000900000009000000010008000000
        00006C000000C30E0000C30E00000001000000010000427B8400DEEFEF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0001010000010101010100
        0000010002020001010101000000010002020200010101000000010100020202
        0001010000000101010002020200010000000101000202020001010000000100
        0202020001010100000001000202000101010100000001010000010101010100
        0000}
      ButtonSettings.CloseButtonHint = 'Close'
      ButtonSettings.PageListButtonHint = 'Page List'
      ButtonSettings.ScrollButtonNextHint = 'Next'
      ButtonSettings.ScrollButtonPrevHint = 'Previous'
      TabSettings.StartMargin = 4
      TabSettings.Shape = tsRightRamp
      TabReorder = False
      ShowShortCutHints = False
      OnChange = OnChandgePG
      TabOrder = 0
      NextPictureChanged = False
      PrevPictureChanged = False
      object tcConnect: TAdvOfficePage
        Left = 1
        Top = 26
        Width = 914
        Height = 517
        Caption = '��������� �����������'
        PageAppearance.BorderColor = 14922381
        PageAppearance.Color = 16640730
        PageAppearance.ColorTo = 16440004
        PageAppearance.ColorMirror = 16440004
        PageAppearance.ColorMirrorTo = 16440004
        PageAppearance.Gradient = ggVertical
        PageAppearance.GradientMirror = ggVertical
        TabAppearance.BorderColor = clNone
        TabAppearance.BorderColorHot = clHighlight
        TabAppearance.BorderColorSelected = clBlack
        TabAppearance.BorderColorSelectedHot = 6343929
        TabAppearance.BorderColorDisabled = clNone
        TabAppearance.BorderColorDown = clNone
        TabAppearance.Color = clBtnFace
        TabAppearance.ColorTo = clWhite
        TabAppearance.ColorSelected = 16571588
        TabAppearance.ColorSelectedTo = 16445929
        TabAppearance.ColorDisabled = clWhite
        TabAppearance.ColorDisabledTo = clSilver
        TabAppearance.ColorHot = 13432063
        TabAppearance.ColorHotTo = 13432063
        TabAppearance.ColorMirror = clWhite
        TabAppearance.ColorMirrorTo = clWhite
        TabAppearance.ColorMirrorHot = 13432063
        TabAppearance.ColorMirrorHotTo = 9556223
        TabAppearance.ColorMirrorSelected = 16445929
        TabAppearance.ColorMirrorSelectedTo = 16181984
        TabAppearance.ColorMirrorDisabled = clWhite
        TabAppearance.ColorMirrorDisabledTo = clSilver
        TabAppearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Font.Color = clWindowText
        TabAppearance.Font.Height = -11
        TabAppearance.Font.Name = 'Tahoma'
        TabAppearance.Font.Style = []
        TabAppearance.Gradient = ggVertical
        TabAppearance.GradientMirror = ggVertical
        TabAppearance.GradientHot = ggVertical
        TabAppearance.GradientMirrorHot = ggVertical
        TabAppearance.GradientSelected = ggVertical
        TabAppearance.GradientMirrorSelected = ggVertical
        TabAppearance.GradientDisabled = ggVertical
        TabAppearance.GradientMirrorDisabled = ggVertical
        TabAppearance.TextColor = clBlack
        TabAppearance.TextColorHot = clBlack
        TabAppearance.TextColorSelected = clBlack
        TabAppearance.TextColorDisabled = clGray
        TabAppearance.ShadowColor = 10708799
        TabAppearance.HighLightColor = 16775871
        TabAppearance.HighLightColorHot = 16643309
        TabAppearance.HighLightColorSelected = 6540536
        TabAppearance.HighLightColorSelectedHot = 12451839
        TabAppearance.HighLightColorDown = 16776144
        TabAppearance.BackGround.Color = 14986888
        TabAppearance.BackGround.ColorTo = 16440004
        TabAppearance.BackGround.Direction = gdVertical
        object sgConnectDB: TAdvStringGrid
          Left = 2
          Top = 30
          Width = 910
          Height = 485
          Cursor = crDefault
          Align = alClient
          DefaultRowHeight = 21
          RowCount = 5
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          GridLineWidth = 2
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goRowSelect]
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 0
          OnClickCell = sgConnectDBClickCell
          OnGetEditorType = OnDBCGetCellType
          OnCheckBoxClick = v_ReportListCheckBoxClick
          OnResize = sgConnectDBResize
          ActiveCellFont.Charset = RUSSIAN_CHARSET
          ActiveCellFont.Color = clWindowText
          ActiveCellFont.Height = -11
          ActiveCellFont.Name = 'Times New Roman'
          ActiveCellFont.Style = [fsBold]
          ActiveCellColor = 9758459
          ActiveCellColorTo = 1414638
          Bands.Active = True
          Bands.PrimaryColor = 16445929
          Bands.SecondaryColor = clBtnHighlight
          CellNode.ShowTree = False
          ControlLook.FixedGradientFrom = 16572875
          ControlLook.FixedGradientTo = 14722429
          ControlLook.ControlStyle = csClassic
          EnhRowColMove = False
          Filter = <>
          FixedFont.Charset = DEFAULT_CHARSET
          FixedFont.Color = clWindowText
          FixedFont.Height = -13
          FixedFont.Name = 'Times New Roman'
          FixedFont.Style = [fsBold]
          FloatFormat = '%.2f'
          PrintSettings.DateFormat = 'dd/mm/yyyy'
          PrintSettings.Font.Charset = DEFAULT_CHARSET
          PrintSettings.Font.Color = clWindowText
          PrintSettings.Font.Height = -11
          PrintSettings.Font.Name = 'MS Sans Serif'
          PrintSettings.Font.Style = []
          PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
          PrintSettings.FixedFont.Color = clWindowText
          PrintSettings.FixedFont.Height = -11
          PrintSettings.FixedFont.Name = 'MS Sans Serif'
          PrintSettings.FixedFont.Style = []
          PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
          PrintSettings.HeaderFont.Color = clWindowText
          PrintSettings.HeaderFont.Height = -11
          PrintSettings.HeaderFont.Name = 'MS Sans Serif'
          PrintSettings.HeaderFont.Style = []
          PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
          PrintSettings.FooterFont.Color = clWindowText
          PrintSettings.FooterFont.Height = -11
          PrintSettings.FooterFont.Name = 'MS Sans Serif'
          PrintSettings.FooterFont.Style = []
          PrintSettings.Borders = pbNoborder
          PrintSettings.Centered = False
          PrintSettings.PageNumSep = '/'
          RowIndicator.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            20000000000000040000C40E0000C40E00000000000000000000FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF001F5C00FF1F5B00FF1F5C00FFFFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF001B6100FF156B06FF1D5F00FF205D00FFFFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00176301FF0D7910FF167510FF1B6001FF205D
            00FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF001A6403FF057709FF097A0EFF157B16FF1A64
            03FF205B00FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF001C6606FF0C861AFF007E0BFF068314FF1486
            1EFF186C0AFF1F5B00FF1F5D00FFFFFFFF00FFFFFF00FFFFFF001E5B00FF1F5D
            00FF1F5D00FF1F5D00FF1F5B00FF1F6C0DFF13952AFF008B17FF008A17FF038B
            1AFF129025FF177712FF1D5D00FF205D00FFFFFFFF00FFFFFF001D5C00FF0878
            0BFF058212FF058414FF058516FF0D9225FF079C2AFF009823FF009823FF0095
            20FF01931FFF0F982AFF17841DFF1C6102FF205C00FF1E5C00FF1C5C00FF078E
            1EFF009B24FF009F28FF00A32BFF00A42DFF00A42DFF00A52EFF00A42EFF00A1
            2CFF009E28FF009923FF0A9C2CFF148F25FF1A6A08FF1E5A00FF1B5C00FF2BA2
            42FF0DAA39FF05AA35FF01AD36FF00AF36FF00B037FF00B137FF00AF36FF00AD
            34FF00AA32FF01A630FF05A12DFF15A73BFF169127FF1C5B00FF195C00FF56BC
            6EFF39C86AFF32C766FF2FCB67FF29CA63FF23C65DFF23C65DFF23C55CFF25C3
            5BFF28C15AFF2CBE5BFF36C162FF229E39FF1A6707FFFFFFFF001A5B00FF3E9B
            45FF2FA748FF2AA645FF2AA746FF3BBE61FF4DDB85FF46D97FFF47D87EFF45D5
            7BFF48D57DFF50D581FF2C9D3EFF1B6002FFFFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF0028781BFF6CE8A0FF56E692FF56E390FF60E7
            99FF63DF93FF2C9135FF1A5900FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF002B781DFF87F0B5FF6FEFA7FF7FF6B5FF6DDE
            97FF258124FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF002D7B20FFAEF7CFFFADFED4FF70D28EFF1C70
            11FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF002D7F23FFC5FFE3FF62BF77FF146303FFFFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF0020690DFF2E8F36FF155A00FFFFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
          ScrollWidth = 14
          SearchFooter.Color = 16572875
          SearchFooter.ColorTo = 14722429
          SearchFooter.FindNextCaption = 'Find &next'
          SearchFooter.FindPrevCaption = 'Find &previous'
          SearchFooter.Font.Charset = DEFAULT_CHARSET
          SearchFooter.Font.Color = clWindowText
          SearchFooter.Font.Height = -11
          SearchFooter.Font.Name = 'MS Sans Serif'
          SearchFooter.Font.Style = []
          SearchFooter.HighLightCaption = 'Highlight'
          SearchFooter.HintClose = 'Close'
          SearchFooter.HintFindNext = 'Find next occurence'
          SearchFooter.HintFindPrev = 'Find previous occurence'
          SearchFooter.HintHighlight = 'Highlight occurences'
          SearchFooter.MatchCaseCaption = 'Match case'
          SelectionColor = clHighlight
          SelectionTextColor = clHighlightText
          WordWrap = False
          ColWidths = (
            64
            64
            64
            64
            64)
          RowHeights = (
            21
            21
            21
            21
            21)
        end
        object AdvPanel: TAdvPanel
          Left = 2
          Top = 2
          Width = 910
          Height = 28
          Align = alTop
          BevelOuter = bvNone
          Color = 16640730
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          UseDockManager = True
          Version = '1.7.9.0'
          BorderColor = clGray
          Caption.Color = 14059353
          Caption.ColorTo = 9648131
          Caption.Font.Charset = DEFAULT_CHARSET
          Caption.Font.Color = clWhite
          Caption.Font.Height = -11
          Caption.Font.Name = 'MS Sans Serif'
          Caption.Font.Style = []
          Caption.GradientDirection = gdVertical
          Caption.Indent = 2
          Caption.ShadeLight = 255
          CollapsColor = clHighlight
          CollapsDelay = 0
          ColorTo = 14986888
          ShadowColor = clBlack
          ShadowOffset = 0
          StatusBar.BorderColor = clNone
          StatusBar.BorderStyle = bsSingle
          StatusBar.Font.Charset = DEFAULT_CHARSET
          StatusBar.Font.Color = clWhite
          StatusBar.Font.Height = -11
          StatusBar.Font.Name = 'Tahoma'
          StatusBar.Font.Style = []
          StatusBar.Color = 14716773
          StatusBar.ColorTo = 16374724
          StatusBar.GradientDirection = gdVertical
          Styler = AdvPanelStyler1
          FullHeight = 0
          object Label36: TLabel
            Left = 318
            Top = 6
            Width = 165
            Height = 17
            Caption = '1.��������� �����������'
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clTeal
            Font.Height = -15
            Font.Name = 'Times New Roman'
            Font.Style = []
            ParentFont = False
            Transparent = True
          end
          object AdvToolBar: TAdvToolBar
            Left = 0
            Top = 0
            Width = 307
            Height = 32
            AllowFloating = True
            Caption = '2'
            CaptionFont.Charset = DEFAULT_CHARSET
            CaptionFont.Color = clWindowText
            CaptionFont.Height = -11
            CaptionFont.Name = 'MS Sans Serif'
            CaptionFont.Style = []
            CompactImageIndex = -1
            TextAutoOptionMenu = 'Add or Remove Buttons'
            TextOptionMenu = 'Options'
            ToolBarStyler = AdvToolBarOfficeStyler1
            ParentStyler = False
            Images = imgEditPannel
            ParentOptionPicture = True
            ParentShowHint = False
            ToolBarIndex = -1
            object AdvToolBarButton121: TAdvToolBarButton
              Left = 9
              Top = 2
              Width = 24
              Height = 28
              Hint = '��������'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 0
              ParentFont = False
              Position = daTop
              Version = '3.1.6.0'
              OnClick = AdvToolBarButton121Click
            end
            object AdvToolBarButton131: TAdvToolBarButton
              Left = 33
              Top = 2
              Width = 24
              Height = 28
              Hint = '���������'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 1
              ParentFont = False
              Position = daTop
              Version = '3.1.6.0'
              OnClick = AdvToolBarButton131Click
            end
            object AdvToolBarButton141: TAdvToolBarButton
              Left = 57
              Top = 2
              Width = 24
              Height = 28
              Hint = '�������'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 2
              ParentFont = False
              Position = daTop
              Version = '3.1.6.0'
              OnClick = AdvToolBarButton141Click
            end
            object AdvToolBarButton151: TAdvToolBarButton
              Left = 81
              Top = 2
              Width = 24
              Height = 28
              Hint = '�����������'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 3
              ParentFont = False
              Position = daTop
              Version = '3.1.6.0'
              OnClick = AdvToolBarButton151Click
            end
            object AdvToolBarButton161: TAdvToolBarButton
              Left = 105
              Top = 2
              Width = 24
              Height = 28
              Hint = '������� ������'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 4
              ParentFont = False
              Position = daTop
              Version = '3.1.6.0'
              OnClick = AdvToolBarButton161Click
            end
            object AdvToolBarButton171: TAdvToolBarButton
              Left = 129
              Top = 2
              Width = 24
              Height = 28
              Hint = '������� ��'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 5
              ParentFont = False
              Position = daTop
              Version = '3.1.6.0'
              OnClick = AdvToolBarButton171Click
            end
            object AdvToolBarButton251: TAdvToolBarButton
              Left = 197
              Top = 2
              Width = 24
              Height = 28
              Hint = '���������������� ������'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 6
              ParentFont = False
              Position = daTop
              Version = '3.1.6.0'
              Visible = False
              OnClick = AdvToolBarButton251Click
            end
            object cnlAdvButt: TAdvToolBarButton
              Left = 245
              Top = 2
              Width = 24
              Height = 28
              Hint = '�����������'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 15
              ParentFont = False
              Position = daTop
              Style = tasCheck
              Version = '3.1.6.0'
              OnClick = cnlAdvButtClick
            end
            object AdvToolBarSeparator17: TAdvToolBarSeparator
              Left = 153
              Top = 2
              Width = 10
              Height = 28
              LineColor = clBtnShadow
            end
            object AdvToolBarButton125: TAdvToolBarButton
              Left = 163
              Top = 2
              Width = 24
              Height = 28
              Hint = '�������������� � Excel'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 19
              ParentFont = False
              Position = daTop
              Version = '3.1.6.0'
            end
            object AdvToolBarButton13: TAdvToolBarButton
              Left = 221
              Top = 2
              Width = 24
              Height = 28
              Hint = '���������� ����'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 17
              ParentFont = False
              Position = daTop
              Version = '3.1.6.0'
              Visible = False
            end
            object AdvToolBarSeparator34: TAdvToolBarSeparator
              Left = 187
              Top = 2
              Width = 10
              Height = 28
              LineColor = clBtnShadow
            end
            object btTehnoCN: TAdvToolBarButton
              Left = 269
              Top = 2
              Width = 24
              Height = 28
              Hint = '��������������� ����������'
              Appearance.CaptionFont.Charset = DEFAULT_CHARSET
              Appearance.CaptionFont.Color = clWindowText
              Appearance.CaptionFont.Height = -11
              Appearance.CaptionFont.Name = 'Tahoma'
              Appearance.CaptionFont.Style = []
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ImageIndex = 22
              ParentFont = False
              Position = daTop
              Style = tasCheck
              Version = '3.1.6.0'
            end
          end
        end
      end
      object tcChannelED: TAdvOfficePage
        Left = 1
        Top = 26
        Width = 914
        Height = 517
        Caption = '��������� �������'
        PageAppearance.BorderColor = 14922381
        PageAppearance.Color = 16640730
        PageAppearance.ColorTo = 16440004
        PageAppearance.ColorMirror = 16440004
        PageAppearance.ColorMirrorTo = 16440004
        PageAppearance.Gradient = ggVertical
        PageAppearance.GradientMirror = ggVertical
        TabAppearance.BorderColor = clNone
        TabAppearance.BorderColorHot = clHighlight
        TabAppearance.BorderColorSelected = clBlack
        TabAppearance.BorderColorSelectedHot = 6343929
        TabAppearance.BorderColorDisabled = clNone
        TabAppearance.BorderColorDown = clNone
        TabAppearance.Color = clBtnFace
        TabAppearance.ColorTo = clWhite
        TabAppearance.ColorSelected = 16571588
        TabAppearance.ColorSelectedTo = 16445929
        TabAppearance.ColorDisabled = clWhite
        TabAppearance.ColorDisabledTo = clSilver
        TabAppearance.ColorHot = 13432063
        TabAppearance.ColorHotTo = 13432063
        TabAppearance.ColorMirror = clWhite
        TabAppearance.ColorMirrorTo = clWhite
        TabAppearance.ColorMirrorHot = 13432063
        TabAppearance.ColorMirrorHotTo = 9556223
        TabAppearance.ColorMirrorSelected = 16445929
        TabAppearance.ColorMirrorSelectedTo = 16181984
        TabAppearance.ColorMirrorDisabled = clWhite
        TabAppearance.ColorMirrorDisabledTo = clSilver
        TabAppearance.Font.Charset = DEFAULT_CHARSET
        TabAppearance.Font.Color = clWindowText
        TabAppearance.Font.Height = -11
        TabAppearance.Font.Name = 'Tahoma'
        TabAppearance.Font.Style = []
        TabAppearance.Gradient = ggVertical
        TabAppearance.GradientMirror = ggVertical
        TabAppearance.GradientHot = ggVertical
        TabAppearance.GradientMirrorHot = ggVertical
        TabAppearance.GradientSelected = ggVertical
        TabAppearance.GradientMirrorSelected = ggVertical
        TabAppearance.GradientDisabled = ggVertical
        TabAppearance.GradientMirrorDisabled = ggVertical
        TabAppearance.TextColor = clBlack
        TabAppearance.TextColorHot = clBlack
        TabAppearance.TextColorSelected = clBlack
        TabAppearance.TextColorDisabled = clGray
        TabAppearance.ShadowColor = 10708799
        TabAppearance.HighLightColor = 16775871
        TabAppearance.HighLightColorHot = 16643309
        TabAppearance.HighLightColorSelected = 6540536
        TabAppearance.HighLightColorSelectedHot = 12451839
        TabAppearance.HighLightColorDown = 16776144
        TabAppearance.BackGround.Color = 14986888
        TabAppearance.BackGround.ColorTo = 16440004
        TabAppearance.BackGround.Direction = gdVertical
        object AdvSplitter1: TAdvSplitter
          Left = 217
          Top = 2
          Width = 3
          Height = 513
          Cursor = crHSplit
          Appearance.BorderColor = clNone
          Appearance.BorderColorHot = clNone
          Appearance.Color = 16640730
          Appearance.ColorTo = 14986888
          Appearance.ColorHot = 13891839
          Appearance.ColorHotTo = 7782911
          GripStyle = sgDots
        end
        object AdvPanel3: TAdvPanel
          Left = 220
          Top = 2
          Width = 692
          Height = 513
          Align = alClient
          BevelOuter = bvNone
          Color = 16640730
          TabOrder = 0
          UseDockManager = True
          Version = '1.7.9.0'
          BorderColor = clGray
          Caption.Color = 14059353
          Caption.ColorTo = 9648131
          Caption.Font.Charset = DEFAULT_CHARSET
          Caption.Font.Color = clWhite
          Caption.Font.Height = -11
          Caption.Font.Name = 'MS Sans Serif'
          Caption.Font.Style = []
          Caption.GradientDirection = gdVertical
          Caption.Indent = 2
          Caption.ShadeLight = 255
          CollapsColor = clHighlight
          CollapsDelay = 0
          ColorTo = 14986888
          ShadowColor = clBlack
          ShadowOffset = 0
          StatusBar.BorderColor = clNone
          StatusBar.BorderStyle = bsSingle
          StatusBar.Font.Charset = DEFAULT_CHARSET
          StatusBar.Font.Color = clWhite
          StatusBar.Font.Height = -11
          StatusBar.Font.Name = 'Tahoma'
          StatusBar.Font.Style = []
          StatusBar.Color = 14716773
          StatusBar.ColorTo = 16374724
          StatusBar.GradientDirection = gdVertical
          Styler = AdvPanelStyler1
          FullHeight = 0
          object sgChannel: TAdvStringGrid
            Left = 0
            Top = 33
            Width = 692
            Height = 480
            Cursor = crDefault
            Align = alClient
            DefaultRowHeight = 21
            RowCount = 5
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clBlack
            Font.Height = -13
            Font.Name = 'Times New Roman'
            Font.Style = []
            GridLineWidth = 2
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goColSizing, goRowSelect]
            ParentFont = False
            ScrollBars = ssVertical
            TabOrder = 0
            OnClickCell = sgChannelClickCell
            OnResize = OnGridEdRZ
            ActiveCellFont.Charset = RUSSIAN_CHARSET
            ActiveCellFont.Color = clWindowText
            ActiveCellFont.Height = -11
            ActiveCellFont.Name = 'Times New Roman'
            ActiveCellFont.Style = [fsBold]
            ActiveCellColor = 9758459
            ActiveCellColorTo = 1414638
            Bands.Active = True
            Bands.PrimaryColor = 16445929
            Bands.SecondaryColor = clBtnHighlight
            CellNode.ShowTree = False
            ControlLook.FixedGradientFrom = 16572875
            ControlLook.FixedGradientTo = 14722429
            ControlLook.ControlStyle = csClassic
            EnhRowColMove = False
            Filter = <>
            FixedFont.Charset = DEFAULT_CHARSET
            FixedFont.Color = clWindowText
            FixedFont.Height = -13
            FixedFont.Name = 'Times New Roman'
            FixedFont.Style = [fsBold]
            FloatFormat = '%.2f'
            PrintSettings.DateFormat = 'dd/mm/yyyy'
            PrintSettings.Font.Charset = DEFAULT_CHARSET
            PrintSettings.Font.Color = clWindowText
            PrintSettings.Font.Height = -11
            PrintSettings.Font.Name = 'MS Sans Serif'
            PrintSettings.Font.Style = []
            PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
            PrintSettings.FixedFont.Color = clWindowText
            PrintSettings.FixedFont.Height = -11
            PrintSettings.FixedFont.Name = 'MS Sans Serif'
            PrintSettings.FixedFont.Style = []
            PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
            PrintSettings.HeaderFont.Color = clWindowText
            PrintSettings.HeaderFont.Height = -11
            PrintSettings.HeaderFont.Name = 'MS Sans Serif'
            PrintSettings.HeaderFont.Style = []
            PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
            PrintSettings.FooterFont.Color = clWindowText
            PrintSettings.FooterFont.Height = -11
            PrintSettings.FooterFont.Name = 'MS Sans Serif'
            PrintSettings.FooterFont.Style = []
            PrintSettings.Borders = pbNoborder
            PrintSettings.Centered = False
            PrintSettings.PageNumSep = '/'
            RowIndicator.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              20000000000000040000C40E0000C40E00000000000000000000FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF001F5C00FF1F5B00FF1F5C00FFFFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF001B6100FF156B06FF1D5F00FF205D00FFFFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00176301FF0D7910FF167510FF1B6001FF205D
              00FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF001A6403FF057709FF097A0EFF157B16FF1A64
              03FF205B00FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF001C6606FF0C861AFF007E0BFF068314FF1486
              1EFF186C0AFF1F5B00FF1F5D00FFFFFFFF00FFFFFF00FFFFFF001E5B00FF1F5D
              00FF1F5D00FF1F5D00FF1F5B00FF1F6C0DFF13952AFF008B17FF008A17FF038B
              1AFF129025FF177712FF1D5D00FF205D00FFFFFFFF00FFFFFF001D5C00FF0878
              0BFF058212FF058414FF058516FF0D9225FF079C2AFF009823FF009823FF0095
              20FF01931FFF0F982AFF17841DFF1C6102FF205C00FF1E5C00FF1C5C00FF078E
              1EFF009B24FF009F28FF00A32BFF00A42DFF00A42DFF00A52EFF00A42EFF00A1
              2CFF009E28FF009923FF0A9C2CFF148F25FF1A6A08FF1E5A00FF1B5C00FF2BA2
              42FF0DAA39FF05AA35FF01AD36FF00AF36FF00B037FF00B137FF00AF36FF00AD
              34FF00AA32FF01A630FF05A12DFF15A73BFF169127FF1C5B00FF195C00FF56BC
              6EFF39C86AFF32C766FF2FCB67FF29CA63FF23C65DFF23C65DFF23C55CFF25C3
              5BFF28C15AFF2CBE5BFF36C162FF229E39FF1A6707FFFFFFFF001A5B00FF3E9B
              45FF2FA748FF2AA645FF2AA746FF3BBE61FF4DDB85FF46D97FFF47D87EFF45D5
              7BFF48D57DFF50D581FF2C9D3EFF1B6002FFFFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF0028781BFF6CE8A0FF56E692FF56E390FF60E7
              99FF63DF93FF2C9135FF1A5900FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF002B781DFF87F0B5FF6FEFA7FF7FF6B5FF6DDE
              97FF258124FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF002D7B20FFAEF7CFFFADFED4FF70D28EFF1C70
              11FFFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF002D7F23FFC5FFE3FF62BF77FF146303FFFFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF0020690DFF2E8F36FF155A00FFFFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
            ScrollWidth = 14
            SearchFooter.Color = 16572875
            SearchFooter.ColorTo = 14722429
            SearchFooter.FindNextCaption = 'Find &next'
            SearchFooter.FindPrevCaption = 'Find &previous'
            SearchFooter.Font.Charset = DEFAULT_CHARSET
            SearchFooter.Font.Color = clWindowText
            SearchFooter.Font.Height = -11
            SearchFooter.Font.Name = 'MS Sans Serif'
            SearchFooter.Font.Style = []
            SearchFooter.HighLightCaption = 'Highlight'
            SearchFooter.HintClose = 'Close'
            SearchFooter.HintFindNext = 'Find next occurence'
            SearchFooter.HintFindPrev = 'Find previous occurence'
            SearchFooter.HintHighlight = 'Highlight occurences'
            SearchFooter.MatchCaseCaption = 'Match case'
            SelectionColor = clHighlight
            SelectionTextColor = clHighlightText
            WordWrap = False
            ColWidths = (
              64
              64
              64
              64
              64)
            RowHeights = (
              21
              21
              21
              21
              21)
          end
          object AdvPanel6: TAdvPanel
            Left = 0
            Top = 0
            Width = 692
            Height = 33
            Align = alTop
            BevelOuter = bvNone
            Color = 16640730
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            UseDockManager = True
            Version = '1.7.9.0'
            BorderColor = clGray
            Caption.Color = 14059353
            Caption.ColorTo = 9648131
            Caption.Font.Charset = DEFAULT_CHARSET
            Caption.Font.Color = clWhite
            Caption.Font.Height = -11
            Caption.Font.Name = 'MS Sans Serif'
            Caption.Font.Style = []
            Caption.GradientDirection = gdVertical
            Caption.Indent = 2
            Caption.ShadeLight = 255
            CollapsColor = clHighlight
            CollapsDelay = 0
            ColorTo = 14986888
            ShadowColor = clBlack
            ShadowOffset = 0
            StatusBar.BorderColor = clNone
            StatusBar.BorderStyle = bsSingle
            StatusBar.Font.Charset = DEFAULT_CHARSET
            StatusBar.Font.Color = clWhite
            StatusBar.Font.Height = -11
            StatusBar.Font.Name = 'Tahoma'
            StatusBar.Font.Style = []
            StatusBar.Color = 14716773
            StatusBar.ColorTo = 16374724
            StatusBar.GradientDirection = gdVertical
            Styler = AdvPanelStyler1
            FullHeight = 0
            object Label1: TLabel
              Left = 222
              Top = 8
              Width = 135
              Height = 17
              Caption = '2.��������� ������� '
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clTeal
              Font.Height = -15
              Font.Name = 'Times New Roman'
              Font.Style = []
              ParentFont = False
              Transparent = True
            end
            object AdvToolBar3: TAdvToolBar
              Left = 0
              Top = 0
              Width = 221
              Height = 31
              AllowFloating = True
              Caption = '2'
              CaptionFont.Charset = DEFAULT_CHARSET
              CaptionFont.Color = clWindowText
              CaptionFont.Height = -11
              CaptionFont.Name = 'MS Sans Serif'
              CaptionFont.Style = []
              CompactImageIndex = -1
              TextAutoOptionMenu = 'Add or Remove Buttons'
              TextOptionMenu = 'Options'
              ToolBarStyler = AdvToolBarOfficeStyler1
              ParentStyler = False
              Images = imgEditPannel
              ParentOptionPicture = True
              ParentShowHint = False
              ToolBarIndex = -1
              object btSaveChann: TAdvToolBarButton
                Left = 9
                Top = 2
                Width = 24
                Height = 27
                Hint = '��������'
                Appearance.CaptionFont.Charset = DEFAULT_CHARSET
                Appearance.CaptionFont.Color = clWindowText
                Appearance.CaptionFont.Height = -11
                Appearance.CaptionFont.Name = 'Tahoma'
                Appearance.CaptionFont.Style = []
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ImageIndex = 0
                ParentFont = False
                Position = daTop
                Version = '3.1.6.0'
                OnClick = btSaveChannClick
              end
              object AdvToolBarButton2: TAdvToolBarButton
                Left = 33
                Top = 2
                Width = 24
                Height = 27
                Hint = '���������'
                Appearance.CaptionFont.Charset = DEFAULT_CHARSET
                Appearance.CaptionFont.Color = clWindowText
                Appearance.CaptionFont.Height = -11
                Appearance.CaptionFont.Name = 'Tahoma'
                Appearance.CaptionFont.Style = []
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ImageIndex = 1
                ParentFont = False
                Position = daTop
                Version = '3.1.6.0'
              end
              object btExec: TAdvToolBarButton
                Left = 125
                Top = 2
                Width = 24
                Height = 27
                Hint = '��������'
                Appearance.CaptionFont.Charset = DEFAULT_CHARSET
                Appearance.CaptionFont.Color = clWindowText
                Appearance.CaptionFont.Height = -11
                Appearance.CaptionFont.Name = 'Tahoma'
                Appearance.CaptionFont.Style = []
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ImageIndex = 6
                ParentFont = False
                Position = daTop
                Version = '3.1.6.0'
                OnClick = btExecClick
              end
              object AdvToolBarSeparator1: TAdvToolBarSeparator
                Left = 81
                Top = 2
                Width = 10
                Height = 27
                LineColor = clBtnShadow
              end
              object AdvToolBarButton9: TAdvToolBarButton
                Left = 91
                Top = 2
                Width = 24
                Height = 27
                Hint = '�������������� � Excel'
                Appearance.CaptionFont.Charset = DEFAULT_CHARSET
                Appearance.CaptionFont.Color = clWindowText
                Appearance.CaptionFont.Height = -11
                Appearance.CaptionFont.Name = 'Tahoma'
                Appearance.CaptionFont.Style = []
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ImageIndex = 19
                ParentFont = False
                Position = daTop
                Version = '3.1.6.0'
              end
              object AdvToolBarSeparator2: TAdvToolBarSeparator
                Left = 149
                Top = 2
                Width = 10
                Height = 27
                LineColor = clBtnShadow
              end
              object AdvToolBarSeparator3: TAdvToolBarSeparator
                Left = 115
                Top = 2
                Width = 10
                Height = 27
                LineColor = clBtnShadow
              end
              object btChannelEd: TAdvToolBarButton
                Left = 183
                Top = 2
                Width = 24
                Height = 27
                Hint = '��������������� ����������'
                Appearance.CaptionFont.Charset = DEFAULT_CHARSET
                Appearance.CaptionFont.Color = clWindowText
                Appearance.CaptionFont.Height = -11
                Appearance.CaptionFont.Name = 'Tahoma'
                Appearance.CaptionFont.Style = []
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ImageIndex = 22
                ParentFont = False
                Position = daTop
                Style = tasCheck
                Version = '3.1.6.0'
              end
              object btOnClearChann: TAdvToolBarButton
                Left = 57
                Top = 2
                Width = 24
                Height = 27
                Hint = '�������� ������'
                Appearance.CaptionFont.Charset = DEFAULT_CHARSET
                Appearance.CaptionFont.Color = clWindowText
                Appearance.CaptionFont.Height = -11
                Appearance.CaptionFont.Name = 'Tahoma'
                Appearance.CaptionFont.Style = []
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ImageIndex = 4
                ParentFont = False
                Position = daTop
                Version = '3.1.6.0'
                OnClick = btOnClearChannClick
              end
              object btChannEd: TAdvToolBarButton
                Left = 159
                Top = 2
                Width = 24
                Height = 27
                Hint = '��������������� ����������'
                Appearance.CaptionFont.Charset = DEFAULT_CHARSET
                Appearance.CaptionFont.Color = clWindowText
                Appearance.CaptionFont.Height = -11
                Appearance.CaptionFont.Name = 'Tahoma'
                Appearance.CaptionFont.Style = []
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ImageIndex = 10
                ParentFont = False
                Position = daTop
                Style = tasCheck
                Version = '3.1.6.0'
                OnClick = btChannEdClick
              end
            end
          end
        end
        object AdvPanel4: TAdvPanel
          Left = 2
          Top = 2
          Width = 215
          Height = 513
          Align = alLeft
          BevelOuter = bvNone
          Color = 16640730
          TabOrder = 1
          UseDockManager = True
          Version = '1.7.9.0'
          BorderColor = clGray
          Caption.Color = 14059353
          Caption.ColorTo = 9648131
          Caption.Font.Charset = DEFAULT_CHARSET
          Caption.Font.Color = clWhite
          Caption.Font.Height = -11
          Caption.Font.Name = 'MS Sans Serif'
          Caption.Font.Style = []
          Caption.GradientDirection = gdVertical
          Caption.Indent = 2
          Caption.ShadeLight = 255
          CollapsColor = clHighlight
          CollapsDelay = 0
          ColorTo = 14986888
          ShadowColor = clBlack
          ShadowOffset = 0
          StatusBar.BorderColor = clNone
          StatusBar.BorderStyle = bsSingle
          StatusBar.Font.Charset = DEFAULT_CHARSET
          StatusBar.Font.Color = clWhite
          StatusBar.Font.Height = -11
          StatusBar.Font.Name = 'Tahoma'
          StatusBar.Font.Style = []
          StatusBar.Color = 14716773
          StatusBar.ColorTo = 16374724
          StatusBar.GradientDirection = gdVertical
          Styler = AdvPanelStyler1
          FullHeight = 0
          object tvObjects: TTreeView
            Left = 0
            Top = 33
            Width = 215
            Height = 480
            Align = alClient
            Images = ImageListTree
            Indent = 19
            TabOrder = 0
            OnClick = OnClickTree
            OnCollapsed = OnCollapsedTree
            OnExpanded = OnExpandTree
          end
          object AdvPanel5: TAdvPanel
            Left = 0
            Top = 0
            Width = 215
            Height = 33
            Align = alTop
            BevelOuter = bvNone
            Color = 16640730
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            UseDockManager = True
            Version = '1.7.9.0'
            BorderColor = clGray
            Caption.Color = 14059353
            Caption.ColorTo = 9648131
            Caption.Font.Charset = DEFAULT_CHARSET
            Caption.Font.Color = clWhite
            Caption.Font.Height = -11
            Caption.Font.Name = 'MS Sans Serif'
            Caption.Font.Style = []
            Caption.GradientDirection = gdVertical
            Caption.Indent = 2
            Caption.ShadeLight = 255
            CollapsColor = clHighlight
            CollapsDelay = 0
            ColorTo = 14986888
            ShadowColor = clBlack
            ShadowOffset = 0
            StatusBar.BorderColor = clNone
            StatusBar.BorderStyle = bsSingle
            StatusBar.Font.Charset = DEFAULT_CHARSET
            StatusBar.Font.Color = clWhite
            StatusBar.Font.Height = -11
            StatusBar.Font.Name = 'Tahoma'
            StatusBar.Font.Style = []
            StatusBar.Color = 14716773
            StatusBar.ColorTo = 16374724
            StatusBar.GradientDirection = gdVertical
            Styler = AdvPanelStyler1
            FullHeight = 0
            object AdvToolBar1: TAdvToolBar
              Left = 0
              Top = 0
              Width = 223
              Height = 31
              AllowFloating = True
              CaptionFont.Charset = DEFAULT_CHARSET
              CaptionFont.Color = clWindowText
              CaptionFont.Height = -11
              CaptionFont.Name = 'MS Sans Serif'
              CaptionFont.Style = []
              CompactImageIndex = -1
              TextAutoOptionMenu = 'Add or Remove Buttons'
              TextOptionMenu = 'Options'
              ToolBarStyler = AdvToolBarOfficeStyler1
              ParentStyler = False
              ParentOptionPicture = True
              ParentShowHint = False
              ToolBarIndex = -1
              object AdvGlowMenuButton6: TAdvGlowMenuButton
                Left = 109
                Top = 2
                Width = 100
                Height = 27
                Caption = '���������'
                FocusType = ftHot
                NotesFont.Charset = DEFAULT_CHARSET
                NotesFont.Color = clWindowText
                NotesFont.Height = -11
                NotesFont.Name = 'Tahoma'
                NotesFont.Style = []
                TabOrder = 0
                Appearance.BorderColor = 14727579
                Appearance.BorderColorHot = 10079963
                Appearance.BorderColorDown = 4548219
                Appearance.BorderColorChecked = 4548219
                Appearance.Color = 15653832
                Appearance.ColorTo = 16178633
                Appearance.ColorChecked = 11918331
                Appearance.ColorCheckedTo = 7915518
                Appearance.ColorDisabled = 15921906
                Appearance.ColorDisabledTo = 15921906
                Appearance.ColorDown = 7778289
                Appearance.ColorDownTo = 4296947
                Appearance.ColorHot = 15465983
                Appearance.ColorHotTo = 11332863
                Appearance.ColorMirror = 15586496
                Appearance.ColorMirrorTo = 16245200
                Appearance.ColorMirrorHot = 5888767
                Appearance.ColorMirrorHotTo = 10807807
                Appearance.ColorMirrorDown = 946929
                Appearance.ColorMirrorDownTo = 5021693
                Appearance.ColorMirrorChecked = 10480637
                Appearance.ColorMirrorCheckedTo = 5682430
                Appearance.ColorMirrorDisabled = 11974326
                Appearance.ColorMirrorDisabledTo = 15921906
                Appearance.GradientHot = ggVertical
                Appearance.GradientMirrorHot = ggVertical
                Appearance.GradientDown = ggVertical
                Appearance.GradientMirrorDown = ggVertical
                Appearance.GradientChecked = ggVertical
                DropDownButton = True
                DropDownMenu = AdvPopupMenuOper
              end
              object btRefreshTree: TAdvGlowMenuButton
                Left = 9
                Top = 2
                Width = 100
                Height = 27
                Caption = '��������'
                FocusType = ftHot
                NotesFont.Charset = DEFAULT_CHARSET
                NotesFont.Color = clWindowText
                NotesFont.Height = -11
                NotesFont.Name = 'Tahoma'
                NotesFont.Style = []
                TabOrder = 1
                OnClick = btRefreshTreeClick
                Appearance.BorderColor = 14727579
                Appearance.BorderColorHot = 10079963
                Appearance.BorderColorDown = 4548219
                Appearance.BorderColorChecked = 4548219
                Appearance.Color = 15653832
                Appearance.ColorTo = 16178633
                Appearance.ColorChecked = 11918331
                Appearance.ColorCheckedTo = 7915518
                Appearance.ColorDisabled = 15921906
                Appearance.ColorDisabledTo = 15921906
                Appearance.ColorDown = 7778289
                Appearance.ColorDownTo = 4296947
                Appearance.ColorHot = 15465983
                Appearance.ColorHotTo = 11332863
                Appearance.ColorMirror = 15586496
                Appearance.ColorMirrorTo = 16245200
                Appearance.ColorMirrorHot = 5888767
                Appearance.ColorMirrorHotTo = 10807807
                Appearance.ColorMirrorDown = 946929
                Appearance.ColorMirrorDownTo = 5021693
                Appearance.ColorMirrorChecked = 10480637
                Appearance.ColorMirrorCheckedTo = 5682430
                Appearance.ColorMirrorDisabled = 11974326
                Appearance.ColorMirrorDisabledTo = 15921906
                Appearance.GradientHot = ggVertical
                Appearance.GradientMirrorHot = ggVertical
                Appearance.GradientDown = ggVertical
                Appearance.GradientMirrorDown = ggVertical
                Appearance.GradientChecked = ggVertical
                DropDownButton = True
                DropDownMenu = AdvPopupMenuSort
              end
            end
          end
        end
      end
    end
  end
  object AdvToolBarOfficeStyler1: TAdvToolBarOfficeStyler
    BorderColor = 15452075
    BorderColorHot = 14731181
    ButtonAppearance.Color = 16640730
    ButtonAppearance.ColorTo = 14986888
    ButtonAppearance.ColorChecked = 9229823
    ButtonAppearance.ColorCheckedTo = 5812223
    ButtonAppearance.ColorDown = 5149182
    ButtonAppearance.ColorDownTo = 9556991
    ButtonAppearance.ColorHot = 13432063
    ButtonAppearance.ColorHotTo = 9556223
    ButtonAppearance.BorderDownColor = clNavy
    ButtonAppearance.BorderHotColor = clNavy
    ButtonAppearance.BorderCheckedColor = clNavy
    ButtonAppearance.CaptionFont.Charset = DEFAULT_CHARSET
    ButtonAppearance.CaptionFont.Color = clWindowText
    ButtonAppearance.CaptionFont.Height = -11
    ButtonAppearance.CaptionFont.Name = 'Tahoma'
    ButtonAppearance.CaptionFont.Style = []
    CaptionAppearance.CaptionColor = clHighlight
    CaptionAppearance.CaptionColorTo = clHighlight
    CaptionAppearance.CaptionBorderColor = clHighlight
    CaptionAppearance.CaptionColorHot = 13432063
    CaptionAppearance.CaptionColorHotTo = 9556223
    CaptionAppearance.CaptionTextColorHot = clBlack
    CaptionFont.Charset = DEFAULT_CHARSET
    CaptionFont.Color = clWindowText
    CaptionFont.Height = -11
    CaptionFont.Name = 'Tahoma'
    CaptionFont.Style = []
    ContainerAppearance.LineColor = clBtnShadow
    ContainerAppearance.Line3D = True
    Color.Color = 16640730
    Color.ColorTo = 14986888
    Color.Direction = gdVertical
    Color.Mirror.Color = 16440004
    Color.Mirror.ColorTo = 16440004
    Color.Mirror.ColorMirror = 16372409
    Color.Mirror.ColorMirrorTo = 16572878
    ColorHot.Color = 16773606
    ColorHot.ColorTo = 16444126
    ColorHot.Direction = gdVertical
    ColorHot.Mirror.Color = 16507602
    ColorHot.Mirror.ColorTo = 16507602
    ColorHot.Mirror.ColorMirror = 16506056
    ColorHot.Mirror.ColorMirrorTo = 16639959
    CompactGlowButtonAppearance.BorderColor = 14727579
    CompactGlowButtonAppearance.BorderColorHot = 10079963
    CompactGlowButtonAppearance.BorderColorDown = 4548219
    CompactGlowButtonAppearance.BorderColorChecked = 4548219
    CompactGlowButtonAppearance.Color = 15653832
    CompactGlowButtonAppearance.ColorTo = 16178633
    CompactGlowButtonAppearance.ColorChecked = 11918331
    CompactGlowButtonAppearance.ColorCheckedTo = 7915518
    CompactGlowButtonAppearance.ColorDisabled = 15921906
    CompactGlowButtonAppearance.ColorDisabledTo = 15921906
    CompactGlowButtonAppearance.ColorDown = 7778289
    CompactGlowButtonAppearance.ColorDownTo = 4296947
    CompactGlowButtonAppearance.ColorHot = 15465983
    CompactGlowButtonAppearance.ColorHotTo = 11332863
    CompactGlowButtonAppearance.ColorMirror = 15586496
    CompactGlowButtonAppearance.ColorMirrorTo = 16245200
    CompactGlowButtonAppearance.ColorMirrorHot = 5888767
    CompactGlowButtonAppearance.ColorMirrorHotTo = 10807807
    CompactGlowButtonAppearance.ColorMirrorDown = 946929
    CompactGlowButtonAppearance.ColorMirrorDownTo = 5021693
    CompactGlowButtonAppearance.ColorMirrorChecked = 10480637
    CompactGlowButtonAppearance.ColorMirrorCheckedTo = 5682430
    CompactGlowButtonAppearance.ColorMirrorDisabled = 11974326
    CompactGlowButtonAppearance.ColorMirrorDisabledTo = 15921906
    CompactGlowButtonAppearance.GradientHot = ggVertical
    CompactGlowButtonAppearance.GradientMirrorHot = ggVertical
    CompactGlowButtonAppearance.GradientDown = ggVertical
    CompactGlowButtonAppearance.GradientMirrorDown = ggVertical
    CompactGlowButtonAppearance.GradientChecked = ggVertical
    DockColor.Color = 16105376
    DockColor.ColorTo = 16440004
    DockColor.Direction = gdHorizontal
    DockColor.Steps = 128
    FloatingWindowBorderColor = 9516288
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    GlowButtonAppearance.BorderColor = 14727579
    GlowButtonAppearance.BorderColorHot = 10079963
    GlowButtonAppearance.BorderColorDown = 4548219
    GlowButtonAppearance.BorderColorChecked = 4548219
    GlowButtonAppearance.Color = 15653832
    GlowButtonAppearance.ColorTo = 16178633
    GlowButtonAppearance.ColorChecked = 11918331
    GlowButtonAppearance.ColorCheckedTo = 7915518
    GlowButtonAppearance.ColorDisabled = 15921906
    GlowButtonAppearance.ColorDisabledTo = 15921906
    GlowButtonAppearance.ColorDown = 7778289
    GlowButtonAppearance.ColorDownTo = 4296947
    GlowButtonAppearance.ColorHot = 15465983
    GlowButtonAppearance.ColorHotTo = 11332863
    GlowButtonAppearance.ColorMirror = 15586496
    GlowButtonAppearance.ColorMirrorTo = 16245200
    GlowButtonAppearance.ColorMirrorHot = 5888767
    GlowButtonAppearance.ColorMirrorHotTo = 10807807
    GlowButtonAppearance.ColorMirrorDown = 946929
    GlowButtonAppearance.ColorMirrorDownTo = 5021693
    GlowButtonAppearance.ColorMirrorChecked = 10480637
    GlowButtonAppearance.ColorMirrorCheckedTo = 5682430
    GlowButtonAppearance.ColorMirrorDisabled = 11974326
    GlowButtonAppearance.ColorMirrorDisabledTo = 15921906
    GlowButtonAppearance.GradientHot = ggVertical
    GlowButtonAppearance.GradientMirrorHot = ggVertical
    GlowButtonAppearance.GradientDown = ggVertical
    GlowButtonAppearance.GradientMirrorDown = ggVertical
    GlowButtonAppearance.GradientChecked = ggVertical
    GroupAppearance.BorderColor = 12763842
    GroupAppearance.Color = 16640730
    GroupAppearance.ColorTo = 15851212
    GroupAppearance.ColorMirror = 15851212
    GroupAppearance.ColorMirrorTo = 16640730
    GroupAppearance.Font.Charset = DEFAULT_CHARSET
    GroupAppearance.Font.Color = clWindowText
    GroupAppearance.Font.Height = -11
    GroupAppearance.Font.Name = 'Tahoma'
    GroupAppearance.Font.Style = []
    GroupAppearance.Gradient = ggVertical
    GroupAppearance.GradientMirror = ggVertical
    GroupAppearance.TextColor = clBlack
    GroupAppearance.CaptionAppearance.CaptionColor = 15915714
    GroupAppearance.CaptionAppearance.CaptionColorTo = 15784385
    GroupAppearance.CaptionAppearance.CaptionTextColor = clBlack
    GroupAppearance.CaptionAppearance.CaptionColorHot = 16769224
    GroupAppearance.CaptionAppearance.CaptionColorHotTo = 16772566
    GroupAppearance.CaptionAppearance.CaptionTextColorHot = clBlack
    GroupAppearance.PageAppearance.BorderColor = 12763842
    GroupAppearance.PageAppearance.Color = 14086910
    GroupAppearance.PageAppearance.ColorTo = 16382457
    GroupAppearance.PageAppearance.ColorMirror = 16382457
    GroupAppearance.PageAppearance.ColorMirrorTo = 16382457
    GroupAppearance.PageAppearance.Gradient = ggVertical
    GroupAppearance.PageAppearance.GradientMirror = ggVertical
    GroupAppearance.PageAppearance.ShadowColor = 12888726
    GroupAppearance.PageAppearance.HighLightColor = 16644558
    GroupAppearance.TabAppearance.BorderColor = clHighlight
    GroupAppearance.TabAppearance.BorderColorHot = clHighlight
    GroupAppearance.TabAppearance.BorderColorSelected = 10534860
    GroupAppearance.TabAppearance.BorderColorSelectedHot = 10534860
    GroupAppearance.TabAppearance.BorderColorDisabled = clNone
    GroupAppearance.TabAppearance.BorderColorDown = clNone
    GroupAppearance.TabAppearance.Color = clBtnFace
    GroupAppearance.TabAppearance.ColorTo = clWhite
    GroupAppearance.TabAppearance.ColorSelected = 10412027
    GroupAppearance.TabAppearance.ColorSelectedTo = 12249340
    GroupAppearance.TabAppearance.ColorDisabled = clNone
    GroupAppearance.TabAppearance.ColorDisabledTo = clNone
    GroupAppearance.TabAppearance.ColorHot = 13432063
    GroupAppearance.TabAppearance.ColorHotTo = 13432063
    GroupAppearance.TabAppearance.ColorMirror = clWhite
    GroupAppearance.TabAppearance.ColorMirrorTo = clWhite
    GroupAppearance.TabAppearance.ColorMirrorHot = 13432063
    GroupAppearance.TabAppearance.ColorMirrorHotTo = 9556223
    GroupAppearance.TabAppearance.ColorMirrorSelected = 12249340
    GroupAppearance.TabAppearance.ColorMirrorSelectedTo = 13955581
    GroupAppearance.TabAppearance.ColorMirrorDisabled = clNone
    GroupAppearance.TabAppearance.ColorMirrorDisabledTo = clNone
    GroupAppearance.TabAppearance.Font.Charset = DEFAULT_CHARSET
    GroupAppearance.TabAppearance.Font.Color = clWindowText
    GroupAppearance.TabAppearance.Font.Height = -11
    GroupAppearance.TabAppearance.Font.Name = 'Tahoma'
    GroupAppearance.TabAppearance.Font.Style = []
    GroupAppearance.TabAppearance.Gradient = ggVertical
    GroupAppearance.TabAppearance.GradientMirror = ggVertical
    GroupAppearance.TabAppearance.GradientHot = ggVertical
    GroupAppearance.TabAppearance.GradientMirrorHot = ggVertical
    GroupAppearance.TabAppearance.GradientSelected = ggVertical
    GroupAppearance.TabAppearance.GradientMirrorSelected = ggVertical
    GroupAppearance.TabAppearance.GradientDisabled = ggVertical
    GroupAppearance.TabAppearance.GradientMirrorDisabled = ggVertical
    GroupAppearance.TabAppearance.TextColor = clBlack
    GroupAppearance.TabAppearance.TextColorHot = clBlack
    GroupAppearance.TabAppearance.TextColorSelected = clBlack
    GroupAppearance.TabAppearance.TextColorDisabled = clWhite
    GroupAppearance.TabAppearance.ShadowColor = 15255470
    GroupAppearance.TabAppearance.HighLightColor = 16775871
    GroupAppearance.TabAppearance.HighLightColorHot = 16643309
    GroupAppearance.TabAppearance.HighLightColorSelected = 6540536
    GroupAppearance.TabAppearance.HighLightColorSelectedHot = 12451839
    GroupAppearance.TabAppearance.HighLightColorDown = 16776144
    GroupAppearance.ToolBarAppearance.BorderColor = 13423059
    GroupAppearance.ToolBarAppearance.BorderColorHot = 13092807
    GroupAppearance.ToolBarAppearance.Color.Color = 15530237
    GroupAppearance.ToolBarAppearance.Color.ColorTo = 16382457
    GroupAppearance.ToolBarAppearance.Color.Direction = gdHorizontal
    GroupAppearance.ToolBarAppearance.ColorHot.Color = 15660277
    GroupAppearance.ToolBarAppearance.ColorHot.ColorTo = 16645114
    GroupAppearance.ToolBarAppearance.ColorHot.Direction = gdHorizontal
    PageAppearance.BorderColor = 14922381
    PageAppearance.Color = 16440004
    PageAppearance.ColorTo = 16440004
    PageAppearance.ColorMirror = 16372409
    PageAppearance.ColorMirrorTo = 16640215
    PageAppearance.Gradient = ggVertical
    PageAppearance.GradientMirror = ggVertical
    PageAppearance.ShadowColor = 13475194
    PageAppearance.HighLightColor = 16644558
    PagerCaption.BorderColor = 15780526
    PagerCaption.Color = 14986888
    PagerCaption.ColorTo = 14986888
    PagerCaption.ColorMirror = 14986888
    PagerCaption.ColorMirrorTo = 14986888
    PagerCaption.Gradient = ggVertical
    PagerCaption.GradientMirror = ggVertical
    PagerCaption.TextColor = clBlue
    PagerCaption.Font.Charset = DEFAULT_CHARSET
    PagerCaption.Font.Color = clWindowText
    PagerCaption.Font.Height = -11
    PagerCaption.Font.Name = 'Tahoma'
    PagerCaption.Font.Style = []
    QATAppearance.BorderColor = 9516288
    QATAppearance.Color = 16640730
    QATAppearance.ColorTo = 14986888
    QATAppearance.FullSizeBorderColor = 14986888
    QATAppearance.FullSizeColor = 14986888
    QATAppearance.FullSizeColorTo = 14986888
    RightHandleColor = 15836789
    RightHandleColorTo = 9516288
    RightHandleColorHot = 13891839
    RightHandleColorHotTo = 7782911
    RightHandleColorDown = 557032
    RightHandleColorDownTo = 8182519
    TabAppearance.BorderColor = clNone
    TabAppearance.BorderColorHot = clHighlight
    TabAppearance.BorderColorSelected = clBlack
    TabAppearance.BorderColorSelectedHot = 6343929
    TabAppearance.BorderColorDisabled = clNone
    TabAppearance.BorderColorDown = clNone
    TabAppearance.Color = clBtnFace
    TabAppearance.ColorTo = clWhite
    TabAppearance.ColorSelected = 16571588
    TabAppearance.ColorSelectedTo = 16445929
    TabAppearance.ColorDisabled = clWhite
    TabAppearance.ColorDisabledTo = clSilver
    TabAppearance.ColorHot = 13432063
    TabAppearance.ColorHotTo = 13432063
    TabAppearance.ColorMirror = clWhite
    TabAppearance.ColorMirrorTo = clWhite
    TabAppearance.ColorMirrorHot = 13432063
    TabAppearance.ColorMirrorHotTo = 9556223
    TabAppearance.ColorMirrorSelected = 16445929
    TabAppearance.ColorMirrorSelectedTo = 16181984
    TabAppearance.ColorMirrorDisabled = clWhite
    TabAppearance.ColorMirrorDisabledTo = clSilver
    TabAppearance.Font.Charset = DEFAULT_CHARSET
    TabAppearance.Font.Color = clWindowText
    TabAppearance.Font.Height = -11
    TabAppearance.Font.Name = 'Tahoma'
    TabAppearance.Font.Style = []
    TabAppearance.Gradient = ggVertical
    TabAppearance.GradientMirror = ggVertical
    TabAppearance.GradientHot = ggVertical
    TabAppearance.GradientMirrorHot = ggVertical
    TabAppearance.GradientSelected = ggVertical
    TabAppearance.GradientMirrorSelected = ggVertical
    TabAppearance.GradientDisabled = ggVertical
    TabAppearance.GradientMirrorDisabled = ggVertical
    TabAppearance.TextColor = clBlack
    TabAppearance.TextColorHot = clBlack
    TabAppearance.TextColorSelected = clBlack
    TabAppearance.TextColorDisabled = clGray
    TabAppearance.ShadowColor = 10708799
    TabAppearance.HighLightColor = 16775871
    TabAppearance.HighLightColorHot = 16643309
    TabAppearance.HighLightColorSelected = 6540536
    TabAppearance.HighLightColorSelectedHot = 12451839
    TabAppearance.HighLightColorDown = 16776144
    TabAppearance.BackGround.Color = 14986888
    TabAppearance.BackGround.ColorTo = 16440004
    TabAppearance.BackGround.Direction = gdVertical
    Left = 392
    Top = 96
  end
  object AdvFormStyler1: TAdvFormStyler
    AutoThemeAdapt = False
    Style = tsOffice2003Blue
    Left = 536
    Top = 160
  end
  object AdvOfficeStatusBarOfficeStyler1: TAdvOfficeStatusBarOfficeStyler
    BorderColor = 14986888
    PanelAppearanceLight.BorderColor = 14922381
    PanelAppearanceLight.BorderColorHot = clGray
    PanelAppearanceLight.BorderColorDown = 10240783
    PanelAppearanceLight.Color = 16440774
    PanelAppearanceLight.ColorTo = 14854530
    PanelAppearanceLight.ColorHot = 13958143
    PanelAppearanceLight.ColorHotTo = 6538487
    PanelAppearanceLight.ColorDown = 9232890
    PanelAppearanceLight.ColorDownTo = 1940207
    PanelAppearanceLight.ColorMirror = 14854530
    PanelAppearanceLight.ColorMirrorTo = 14854530
    PanelAppearanceLight.ColorMirrorHot = 6538487
    PanelAppearanceLight.ColorMirrorHotTo = 6538487
    PanelAppearanceLight.ColorMirrorDown = 1940207
    PanelAppearanceLight.ColorMirrorDownTo = 1940207
    PanelAppearanceLight.TextColor = clBlack
    PanelAppearanceLight.TextColorHot = clBlack
    PanelAppearanceLight.TextColorDown = clBlack
    PanelAppearanceLight.TextStyle = []
    PanelAppearanceDark.BorderColor = clNone
    PanelAppearanceDark.BorderColorHot = clGray
    PanelAppearanceDark.BorderColorDown = 10240783
    PanelAppearanceDark.Color = 13861717
    PanelAppearanceDark.ColorTo = 10240783
    PanelAppearanceDark.ColorHot = 13958143
    PanelAppearanceDark.ColorHotTo = 6538487
    PanelAppearanceDark.ColorDown = 9232890
    PanelAppearanceDark.ColorDownTo = 1940207
    PanelAppearanceDark.ColorMirror = 10240783
    PanelAppearanceDark.ColorMirrorTo = 10240783
    PanelAppearanceDark.ColorMirrorHot = 6538487
    PanelAppearanceDark.ColorMirrorHotTo = 6538487
    PanelAppearanceDark.ColorMirrorDown = 1940207
    PanelAppearanceDark.ColorMirrorDownTo = 1940207
    PanelAppearanceDark.TextColor = clWhite
    PanelAppearanceDark.TextColorHot = clWhite
    PanelAppearanceDark.TextColorDown = clWhite
    PanelAppearanceDark.TextStyle = []
    Left = 552
    Top = 352
  end
  object AdvPanelStyler1: TAdvPanelStyler
    Tag = 0
    Settings.AnchorHint = False
    Settings.BevelInner = bvNone
    Settings.BevelOuter = bvNone
    Settings.BevelWidth = 1
    Settings.BorderColor = clGray
    Settings.BorderShadow = False
    Settings.BorderStyle = bsNone
    Settings.BorderWidth = 0
    Settings.CanMove = False
    Settings.CanSize = False
    Settings.Caption.Color = 14059353
    Settings.Caption.ColorTo = 9648131
    Settings.Caption.Font.Charset = DEFAULT_CHARSET
    Settings.Caption.Font.Color = clWhite
    Settings.Caption.Font.Height = -11
    Settings.Caption.Font.Name = 'MS Sans Serif'
    Settings.Caption.Font.Style = []
    Settings.Caption.GradientDirection = gdVertical
    Settings.Caption.Indent = 2
    Settings.Caption.ShadeLight = 255
    Settings.Collaps = False
    Settings.CollapsColor = clHighlight
    Settings.CollapsDelay = 0
    Settings.CollapsSteps = 0
    Settings.Color = 16640730
    Settings.ColorTo = 14986888
    Settings.ColorMirror = clNone
    Settings.ColorMirrorTo = clNone
    Settings.Cursor = crDefault
    Settings.Font.Charset = DEFAULT_CHARSET
    Settings.Font.Color = clWindowText
    Settings.Font.Height = -11
    Settings.Font.Name = 'MS Sans Serif'
    Settings.Font.Style = []
    Settings.FixedTop = False
    Settings.FixedLeft = False
    Settings.FixedHeight = False
    Settings.FixedWidth = False
    Settings.Height = 120
    Settings.Hover = False
    Settings.HoverColor = clNone
    Settings.HoverFontColor = clNone
    Settings.Indent = 0
    Settings.ShadowColor = clBlack
    Settings.ShadowOffset = 0
    Settings.ShowHint = False
    Settings.ShowMoveCursor = False
    Settings.StatusBar.BorderColor = clNone
    Settings.StatusBar.BorderStyle = bsSingle
    Settings.StatusBar.Font.Charset = DEFAULT_CHARSET
    Settings.StatusBar.Font.Color = clWhite
    Settings.StatusBar.Font.Height = -11
    Settings.StatusBar.Font.Name = 'Tahoma'
    Settings.StatusBar.Font.Style = []
    Settings.StatusBar.Color = 14716773
    Settings.StatusBar.ColorTo = 16374724
    Settings.StatusBar.GradientDirection = gdVertical
    Settings.TextVAlign = tvaTop
    Settings.TopIndent = 0
    Settings.URLColor = clBlue
    Settings.Width = 0
    Style = psOffice2003Blue
    Left = 448
    Top = 232
  end
  object AdvPopupMenuSys: TAdvPopupMenu
    MenuStyler = AdvMenuOfficeStyler1
    Version = '2.5.2.4'
    Left = 72
    Top = 24
    object N1: TMenuItem
      Caption = '�����'
      OnClick = OnExitClick
    end
  end
  object AdvPopupMenuCount: TAdvPopupMenu
    MenuStyler = AdvMenuOfficeStyler1
    Version = '2.5.2.4'
    Left = 176
    Top = 24
  end
  object AdvPopupMenuChan: TAdvPopupMenu
    MenuStyler = AdvMenuOfficeStyler1
    Version = '2.5.2.4'
    Left = 320
    Top = 16
  end
  object AdvPopupMenuOpc: TAdvPopupMenu
    MenuStyler = AdvMenuOfficeStyler1
    Version = '2.5.2.4'
    Left = 416
    Top = 16
  end
  object AdvMenuOfficeStyler1: TAdvMenuOfficeStyler
    AntiAlias = aaNone
    AutoThemeAdapt = False
    Style = osOffice2003Blue
    Background.Position = bpCenter
    Background.Color = 16185078
    Background.ColorTo = 16185078
    ButtonAppearance.DownColor = 5149182
    ButtonAppearance.DownColorTo = 9556991
    ButtonAppearance.HoverColor = 13432063
    ButtonAppearance.HoverColorTo = 9556223
    ButtonAppearance.DownBorderColor = clNavy
    ButtonAppearance.HoverBorderColor = clNavy
    ButtonAppearance.CaptionFont.Charset = DEFAULT_CHARSET
    ButtonAppearance.CaptionFont.Color = clWindowText
    ButtonAppearance.CaptionFont.Height = -11
    ButtonAppearance.CaptionFont.Name = 'Tahoma'
    ButtonAppearance.CaptionFont.Style = []
    IconBar.Color = 16773091
    IconBar.ColorTo = 14986631
    IconBar.CheckBorder = clNavy
    IconBar.RadioBorder = clNavy
    IconBar.SeparatorColor = 12961221
    SelectedItem.BorderColor = clNavy
    SelectedItem.Font.Charset = DEFAULT_CHARSET
    SelectedItem.Font.Color = clWindowText
    SelectedItem.Font.Height = -11
    SelectedItem.Font.Name = 'Tahoma'
    SelectedItem.Font.Style = []
    SelectedItem.NotesFont.Charset = DEFAULT_CHARSET
    SelectedItem.NotesFont.Color = clWindowText
    SelectedItem.NotesFont.Height = -8
    SelectedItem.NotesFont.Name = 'Tahoma'
    SelectedItem.NotesFont.Style = []
    SelectedItem.CheckBorder = clNavy
    SelectedItem.RadioBorder = clNavy
    RootItem.Color = 16105118
    RootItem.ColorTo = 16240050
    RootItem.Font.Charset = DEFAULT_CHARSET
    RootItem.Font.Color = clWindowText
    RootItem.Font.Height = -11
    RootItem.Font.Name = 'Tahoma'
    RootItem.Font.Style = []
    RootItem.SelectedColor = 16773091
    RootItem.SelectedColorTo = 15185299
    RootItem.SelectedBorderColor = 9841920
    RootItem.HoverColor = 13432063
    RootItem.HoverColorTo = 10147583
    Glyphs.SubMenu.Data = {
      5A000000424D5A000000000000003E0000002800000004000000070000000100
      0100000000001C0000000000000000000000020000000200000000000000FFFF
      FF0070000000300000001000000000000000100000003000000070000000}
    Glyphs.Check.Data = {
      7E000000424D7E000000000000003E0000002800000010000000100000000100
      010000000000400000000000000000000000020000000200000000000000FFFF
      FF00FFFF0000FFFF0000FFFF0000FFFF0000FDFF0000F8FF0000F07F0000F23F
      0000F71F0000FF8F0000FFCF0000FFEF0000FFFF0000FFFF0000FFFF0000FFFF
      0000}
    Glyphs.Radio.Data = {
      7E000000424D7E000000000000003E0000002800000010000000100000000100
      010000000000400000000000000000000000020000000200000000000000FFFF
      FF00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FC3F0000F81F0000F81F
      0000F81F0000F81F0000FC3F0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF
      0000}
    SideBar.Font.Charset = DEFAULT_CHARSET
    SideBar.Font.Color = clWhite
    SideBar.Font.Height = -19
    SideBar.Font.Name = 'Tahoma'
    SideBar.Font.Style = [fsBold, fsItalic]
    SideBar.Image.Position = bpCenter
    SideBar.Background.Position = bpCenter
    SideBar.SplitterColorTo = clBlack
    Separator.Color = 13339754
    Separator.GradientType = gtBoth
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    NotesFont.Charset = DEFAULT_CHARSET
    NotesFont.Color = clGray
    NotesFont.Height = -8
    NotesFont.Name = 'Tahoma'
    NotesFont.Style = []
    MenuBorderColor = 9841920
    Left = 488
    Top = 16
  end
  object AdvOfficePagerOfficeStyler1: TAdvOfficePagerOfficeStyler
    PageAppearance.BorderColor = 14922381
    PageAppearance.Color = 16640730
    PageAppearance.ColorTo = 16440004
    PageAppearance.ColorMirror = 16440004
    PageAppearance.ColorMirrorTo = 16440004
    PageAppearance.Gradient = ggVertical
    PageAppearance.GradientMirror = ggVertical
    TabAppearance.BorderColor = clNone
    TabAppearance.BorderColorHot = clHighlight
    TabAppearance.BorderColorSelected = clBlack
    TabAppearance.BorderColorSelectedHot = 6343929
    TabAppearance.BorderColorDisabled = clNone
    TabAppearance.BorderColorDown = clNone
    TabAppearance.Color = clBtnFace
    TabAppearance.ColorTo = clWhite
    TabAppearance.ColorSelected = 16571588
    TabAppearance.ColorSelectedTo = 16445929
    TabAppearance.ColorDisabled = clWhite
    TabAppearance.ColorDisabledTo = clSilver
    TabAppearance.ColorHot = 13432063
    TabAppearance.ColorHotTo = 13432063
    TabAppearance.ColorMirror = clWhite
    TabAppearance.ColorMirrorTo = clWhite
    TabAppearance.ColorMirrorHot = 13432063
    TabAppearance.ColorMirrorHotTo = 9556223
    TabAppearance.ColorMirrorSelected = 16445929
    TabAppearance.ColorMirrorSelectedTo = 16181984
    TabAppearance.ColorMirrorDisabled = clWhite
    TabAppearance.ColorMirrorDisabledTo = clSilver
    TabAppearance.Font.Charset = DEFAULT_CHARSET
    TabAppearance.Font.Color = clWindowText
    TabAppearance.Font.Height = -11
    TabAppearance.Font.Name = 'Tahoma'
    TabAppearance.Font.Style = []
    TabAppearance.Gradient = ggVertical
    TabAppearance.GradientMirror = ggVertical
    TabAppearance.GradientHot = ggVertical
    TabAppearance.GradientMirrorHot = ggVertical
    TabAppearance.GradientSelected = ggVertical
    TabAppearance.GradientMirrorSelected = ggVertical
    TabAppearance.GradientDisabled = ggVertical
    TabAppearance.GradientMirrorDisabled = ggVertical
    TabAppearance.TextColor = clBlack
    TabAppearance.TextColorHot = clBlack
    TabAppearance.TextColorSelected = clBlack
    TabAppearance.TextColorDisabled = clGray
    TabAppearance.ShadowColor = 10708799
    TabAppearance.HighLightColor = 16775871
    TabAppearance.HighLightColorHot = 16643309
    TabAppearance.HighLightColorSelected = 6540536
    TabAppearance.HighLightColorSelectedHot = 12451839
    TabAppearance.HighLightColorDown = 16776144
    TabAppearance.BackGround.Color = 14986888
    TabAppearance.BackGround.ColorTo = 16440004
    TabAppearance.BackGround.Direction = gdVertical
    GlowButtonAppearance.BorderColor = 14727579
    GlowButtonAppearance.BorderColorHot = 10079963
    GlowButtonAppearance.BorderColorDown = 4548219
    GlowButtonAppearance.BorderColorChecked = 4548219
    GlowButtonAppearance.Color = 15653832
    GlowButtonAppearance.ColorTo = 16178633
    GlowButtonAppearance.ColorChecked = 11918331
    GlowButtonAppearance.ColorCheckedTo = 7915518
    GlowButtonAppearance.ColorDisabled = 15921906
    GlowButtonAppearance.ColorDisabledTo = 15921906
    GlowButtonAppearance.ColorDown = 7778289
    GlowButtonAppearance.ColorDownTo = 4296947
    GlowButtonAppearance.ColorHot = 15465983
    GlowButtonAppearance.ColorHotTo = 11332863
    GlowButtonAppearance.ColorMirror = 15586496
    GlowButtonAppearance.ColorMirrorTo = 16245200
    GlowButtonAppearance.ColorMirrorHot = 5888767
    GlowButtonAppearance.ColorMirrorHotTo = 10807807
    GlowButtonAppearance.ColorMirrorDown = 946929
    GlowButtonAppearance.ColorMirrorDownTo = 5021693
    GlowButtonAppearance.ColorMirrorChecked = 10480637
    GlowButtonAppearance.ColorMirrorCheckedTo = 5682430
    GlowButtonAppearance.ColorMirrorDisabled = 11974326
    GlowButtonAppearance.ColorMirrorDisabledTo = 15921906
    GlowButtonAppearance.GradientHot = ggVertical
    GlowButtonAppearance.GradientMirrorHot = ggVertical
    GlowButtonAppearance.GradientDown = ggVertical
    GlowButtonAppearance.GradientMirrorDown = ggVertical
    GlowButtonAppearance.GradientChecked = ggVertical
    Left = 792
    Top = 193
  end
  object AdvPopupMenuOper: TAdvPopupMenu
    MenuStyler = AdvMenuOfficeStyler1
    Version = '2.5.2.4'
    Left = 176
    Top = 88
  end
  object AdvPopupMenuSort: TAdvPopupMenu
    MenuStyler = AdvMenuOfficeStyler1
    Version = '2.5.2.4'
    Left = 72
    Top = 88
  end
  object imgEditPannel: TImageList
    Left = 333
    Top = 122
    Bitmap = {
      494C010117001800040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000006000000001002000000000000060
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00F7F7F70000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FEFEFE00F9FBFC00F5F8FA00F5F8FA00FAFBFC00FEFEFE000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000F7F7
      F70063635A006B6B6B0063636300C6C6C600FFFFFF0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FDFD
      FE00E9F2F500CAE1E80097BED0006F9CBA00719EBB009EC3D300D0E4EB00ECF4
      F600FEFEFE00000000000000000000000000DFDFDFFF3E3F40FF505050FFE3E3
      E3FF000000000000000000000000000000000000000000000000000000000000
      0000D9D8D8FF3A1619FF595959FFF6F5F6FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400CECEC600CECEC600DEDEDE00C6BDBD005A5A5A007B7B7B00DEDEDE00FFFF
      FF00000000000000000000000000000000000000000000000000F9FBFC00D2E5
      EB00426FA1001C458E00244E94001D4490001D448F00244B9200183C85005480
      A900D7E7ED00FBFCFD000000000000000000D3D2CEFF696969FFECEAE5FF1C1C
      1CFF3F3F3FFFEDEDEDFF00000000000000000000000000000000B9B9B9FF2022
      21FF570308FFC60713FFFF0013FFECEAEAFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00D6D6
      CE00DED6D600D6D6CE00D6D6CE00D6CECE00CECEC600E7E7DE00ADADA5004A4A
      4A0094949400E7E7E700000000000000000000000000FAFCFC00CAE0E700139A
      F9001F85E4000731890009338A0009328A0008318800082F860004277F002097
      FA001690ED00D5E6EC00FDFDFE0000000000C4C5C6FFF5F5F5FFADADACFFD2D3
      D1FF262626FF232323FF5C5C5CFFF5F5F5FF9B9B9BFF202020FF262828FF5001
      05FFC30B18FFFF0C1FFFFF0010FFFBF8F8FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C6005A5A
      5A00DEDED600DED6D600DED6D600D6D6CE00D6D6CE00D6D6CE00D6CEC600D6CE
      CE00E7E7DE009C94940052525200FFFFFF0000000000E1EDF100139BF8001E96
      FF001D9AFF000D449A000B3D92000B3B91000B398F000A388E000E4FAE00188D
      FF00198BFF001C8FE900E9F2F50000000000F3F3F3FFA3A3A2FFE1DEDBFFD5D3
      D1FFA3A7A7FF676767FF383838FF353535FF363636FF473D3DFF560004FFB305
      10FFFD1729FFE0212EFF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000073736B00E7E7
      DE00E7DEDE00DEDED600DEDED600DED6D600D6D6CE00D6D6CE00D6D6CE00D6D6
      CE00D6D6CE00CEC6C600DEDED600E7E7E700F8FAFC0062A7D70020A1FF0020A0
      FF00209FFF0021A1FE000D4193000D4497000D4296000B3A8D001E9CFF001B94
      FF001A90FF001898FF008CBAD700FBFCFD0000000000FDFDFDFFB3B4B4FFCECD
      CAFFD7D6D4FF6E7274FF8C8C8CFFB8B7B8FF5A3335FF7E0B11FFC6000BFFF61B
      2AFFC0777DFF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F7F7F70031313100EFE7
      E700E7E7E700E7E7DE0084BD9400219C4A00DED6D600DED6CE00D6D6CE00D6D6
      CE00D6D6CE00CEC6C600DED6D600FFFFFF00F0F6F80015A9FF0023A5FF0023A8
      FF0023A8FF0023A7FF001977CB00114E9E00104A9C001B89E4001F9EFF001E9A
      FF001C97FF001B91FF000D93F400F5F9FA000000000000000000F9F9F9FFC8CB
      CAFFD6D5D2FFE1E0DDFF505557FF9F9899FFB2292EFFEC071AFFF70D19FF7D6F
      71FF808080FFA3A3A3FF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000008C8C8C006B846300EFEF
      EF00EFEFE700EFE7E7002994420021944200219C4A0084CE9C00E7DEDE00D6D6
      CE00D6D6CE00D6CEC600BDBDB50000000000D4E5EC001DB2FF0026AEFF0026B0
      FF0027B0FF0027B0FF0028B4FF001354A100145BA90024ACFF0023A5FF0021A2
      FF001F9DFF001D99FF000F9FFF00EBF3F6000000000000000000FDFDFDFF0000
      0000D0D1D2FFE4E2DFFFCCCDCCFF860108FFFF5E6FFFFC0916FF969898FF9D9D
      9DFFD6D6D6FFAAAAAAFF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF004A4A4A00297B1800217B
      2100318C3900CEDECE00E7E7DE00DEE7DE008CC69C00219C4A0021A5520029AD
      5A00BDDEC600CECEC600E7E7E70000000000BAD6E50038BEFF0027B5FF002AB8
      FF002AB8FF002AB8FF002AB8FF0026A6EF0028B3FF0027B1FF0026ADFF0024A9
      FF0022A5FF001F9FFF002BAAFF00DAE9EF000000000000000000000000000000
      000000000000BFC0C1FF505353FFCBD0D2FF726164FF00000000FAFAFAFFF4F4
      F4FFFCFCFCFF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C6C6C60063636300F7F7F700E7EF
      DE004A944A0021842900218C310063AD6B0084C69400E7E7DE00DEDED60052AD
      730021A55A00D6CECE000000000000000000C4DBE600347DB900357DB9002171
      B400196EB2001A6FB2001A6EB100218ED1001B75BA001763AA00155EA7001156
      A3001C58A4002C60A7002C5FA500E4EEF3000000000000000000000000000000
      0000FAFBFBFF8F908FFFC0C2C2FFC7C8C7FFFDFCFDFF7B7D7FFF000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C6C6BD00FFFFF700FFF7F700F7F7
      F700F7F7F700F7F7EF00ADCEA50021843100218C3100EFEFEF00E7E7DE00E7DE
      DE00CECEC600BDBDBD000000000000000000F0F6F8004F98CA003F8EC4004090
      C5004192C600378CC3002A80BC0037CCFF0037C8FF002875B500347CBA003B7C
      BA003875B600366FB2004879B600FDFDFE00000000000000000000000000DDDE
      DEFFC9C8C6FFFDFDFDFF00000000DCDCDDFFBFBEBFFFFFFFFFFF575E61FF6668
      6AFFDCDDDDFF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E7DED600F7F7F700FFFFF700FFFF
      F700FFF7F700F7F7F700F7F7EF00C6D6BD00F7EFEF00EFEFE700EFEFE700E7E7
      E700DEDED600FFFFFF000000000000000000000000005799CD00469ACB004A9F
      CE004AA0CE004A9FCD0056CFF70058D5FF0057D3FF004FB6E800458DC4004388
      C1004181BD003C78B8004E7EB300FEFEFE0000000000000000008A8B8AFFBFC0
      C1FF00000000000000000000000000000000E4E4E5FF676B6DFF272B2EFFF8F8
      F6FF717476FF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000F7F7F700E7DED600DEDE
      D600FFFFFF00FFF7F700F7F7F700F7F7F700F7F7EF00F7EFEF00EFEFE700DEDE
      D600ADADAD0000000000000000000000000000000000C2DAE70086C7E20053AC
      D50055AFD60057B6DC0062E0FF0061DDFF0060DBFF005FDAFF004E99CB004C93
      C700478AC20083B1D600E5EFF3000000000000000000D1D1D1FFC6C7C9FF0000
      0000000000000000000000000000000000007B7E7EFF686B6CFFD7D7D7FFCCCD
      CDFFB0B5B5FF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F7F7F700DEDED600DEDEDE00FFF7F700F7F7F700F7F7EF00F7EFEF00DED6
      D600F7F7F70000000000000000000000000000000000000000006AA8D30097D5
      E9005BB9DA006CEAFF006BE7FF006AE4FF0069E1FF0067DEFF0064D7FC00519A
      CB0098C5E00085ADCD00FEFEFE00000000000000000000000000000000000000
      000000000000000000000000000000000000C0C1C1FFFFFFFFFF808485FFCBCC
      CCFFFBFFFFFF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F7F7EF00D6D6CE00E7E7DE00D6D6CE00D6CE
      CE00000000000000000000000000000000000000000000000000000000007BB4
      D900B3F4FC0096F2FF0076EDFF006FEAFF006EE6FF0073E4FF0098E8FF00A5DC
      F0008EB5D3000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF8083
      84FFE2E2E3FF0000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFF7F7000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000EAF2F6007CCBF000A3F4FF00B8FDFF00B5FAFF0098EAFF007AC2EA00F9FB
      FC00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FDFDFDFFFAFAFAFF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFF7EF00EFE7DE00EFDE
      D600EFDED600EFDED600EFDED600EFDED600EFDED600EFDED600EFDED600EFDE
      D600EFDEDE00F7E7E700FFFFFF000000000000000000FFFFFF00F7F7FF00EFEF
      FF00EFEFFF00EFEFFF00EFEFFF00EFEFFF00EFEFFF00EFEFFF00EFEFFF00EFEF
      FF00EFEFFF00F7F7FF00FFFFFF000000000000000000FFFFFF00EFF7F700E7F7
      F700E7F7F700E7F7F700E7F7F700E7F7F700E7F7F700E7F7F700E7F7F700E7F7
      F700E7F7F700F7F7FF00FFFFFF00000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00DEDEDE00A59C9C00A59C
      9400D6D6D600FFFFFF000000000000000000F7EFEF00CE9C8400CE844200CE8C
      4200CE8C4200CE8C4A00CE8C4A00CE8C4A00CE8C4A00CE8C4200CE844200CE84
      4200C6844200C67B4A00EFDED600FFFFFF00F7F7FF00CECEEF006B6BD6005A5A
      D6005A5AD6005A5AD6005A5AD6005A5AD6005A5AD6005A5AD6005A5AD6005A5A
      D6005A5AD600A5A5E700E7E7F700FFFFFF00F7FFFF00C6DEE7005A9CD600529C
      D600529CD600529CD600529CD600529CD600529CD600529CD600529CD6005294
      D6005294D60073ADCE00DEEFF700FFFFFF000000000000000000D6944A00D694
      5200D6945200D6945200D6945200D6945200C6B5A500EFD6CE00E78C6300E78C
      6300EFDED600A59C9400F7F7F70000000000E7C6BD00CE843100C6732100C67B
      2100C67B2100CE7B2900CE7B2900CE7B2900CE7B2100C67B2100C6732100C673
      2100C6732100BD6B1800C67B3900FFF7F700DEDEF7003131CE000000B5000000
      BD000000BD000000BD000000BD000000BD000000BD000000BD000000BD000000
      BD000000B5001818BD008C8CDE00FFFFFF00E7EFF7004A9CFF00108CFF00108C
      FF00108CFF00108CFF00108CFF00108CFF00108CFF001084FF001084FF000884
      FF00087BFF001084FF004A94D600F7F7FF000000000000000000DEA56300E7AD
      7300E7AD7300E7AD7300DEAD7300DECEBD00E77B5200F7F7F700EFF7F700E763
      2900E7520800E78C6300A59C9400FFFFFF00CE946B00CE7B2900CE7B2900CE84
      2900CE843100CE843100CE843100CE843100CE843100CE842900CE842900CE7B
      2900CE7B2900C6732100C6732100FFF7F7007B7BDE000000BD000000C6000000
      C6000000C6000000C6000000C6000000C6000000C6000000C6000000C6000000
      C6000000C6000000BD000808C600F7F7FF00B5D6E7001894FF001894FF001894
      FF001894FF001894FF001894FF001894FF001894FF001894FF00188CFF00188C
      FF001084FF001084FF001084FF00F7FFFF000000000000000000E7B57B00EFBD
      8C00EFBD8C00EFBD8C00DEB58400E7CEBD00EF6B1800F7F7EF00FF7B2100F77B
      2900F7732100EF6B1800EFDED600DEDEDE00CE946B00CE843100D6843100D68C
      3100D68C3900D68C3100EFC69400D6842900D6944200DE9C4A00D68C3100D684
      3100CE843100CE7B2900CE7B2900FFF7F7006363DE000000C6000000CE000000
      CE000000CE000000CE000000CE000000CE000000CE000000CE000000CE000000
      CE000000CE000000C6000000C600F7F7FF00ADCEDE00189CFF00189CFF00189C
      FF00189CFF00189CFF0039ADFF001094FF001094FF001894FF001894FF001894
      FF00188CFF00188CFF001084FF00F7FFFF000000000000000000EFC68C00F7CE
      A500F7D6A500F7D6A500E7CEAD00E78C4A00E79C6300FFFFFF00FF943900FF94
      3900DEB59C00F78C3100E7A57300A5A59C00CE946B00D68C3900DE944200DE94
      4200DE944200DE943900DEAD7300FFFFFF00F7E7D600D68C3100DE8C3900D68C
      3900D68C3900D6843100CE843100FFF7F7006363DE000000CE000000D6000000
      D6000000D6000000D600F7F7F700EFEFFF00FFFFFF002121D6000000D6000000
      D6000000D6000000CE000000CE00F7F7FF00ADCEDE0021A5FF0021A5FF0021A5
      FF0021A5FF0010A5FF00ADCEEF00FFFFFF00FFFFFF00299CF700109CFF00189C
      FF001894FF001894FF001084FF00F7FFFF000000000000000000F7D6A500FFE7
      BD00FFE7BD00FFE7BD00EFDEBD00E7945200FFAD4A00F7E7D600FFAD5200FFAD
      5200FFFFFF00DEBD9400EFA57300ADA5A500CE947300DE9C5200E7A55200E7A5
      5A00F7CEA500FFFFFF00EFBD7B00E7A54A00E79C4200F7DEBD00FFFFFF00DE94
      3900DE943900D68C3900CE843100FFF7F7006363DE001010D6001010DE001818
      DE002929E700C6C6F7000000E7000000CE000000D6003939E7009C9CF7000000
      DE000000D6000000D6000000CE00F7F7FF00ADCEDE0031ADFF0039B5FF0039B5
      FF005AC6FF00FFFFFF0039B5FF0010A5FF00089CFF0073C6FF00E7F7FF00189C
      FF00189CFF001894FF00188CFF00F7FFFF000000000000000000FFDEB500FFEF
      CE00FFEFD600FFEFD600F7E7C600CEB59C00FFB55A00FFD69C00FFBD7300FFBD
      6B00F7EFDE00F7B56300F7DECE00E7E7E700CE947300E7AD6300E7AD6B00EFB5
      7300E7AD5A00FFFFF700FFFFFF00FFFFFF00FFFFFF00FFFFFF00EFC69C00E79C
      4200DE9C4200DE944200CE8C3900FFF7F7006363E7002121DE002121E7001818
      E7006B6BD600FFFFFF00FFFFFF00F7F7FF00FFFFFF00FFFFFF00D6D6EF000000
      E7000000DE000000DE000000D600F7F7FF00ADCEDE0042B5FF0042BDFF0042BD
      FF0042ADEF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDD6EF0018A5
      FF0018A5FF00189CFF00188CFF00F7FFFF000000000000000000FFE7BD00FFF7
      DE00FFF7DE00FFF7DE00FFF7DE00F7EFE700EFA56300FFB55A00F7C68C00EFF7
      F700FFFFFF00E7A56B00D6CEC60000000000CE947300EFB57300EFC68400FFFF
      FF00FFDEBD00F7BD7B00EFB57300EFC68C00EFBD8400EFB57300F7C68C00FFFF
      FF00FFF7EF00E79C4200CE944200FFF7F7006363E7003131E7002929EF00FFFF
      FF003939F7002929D6009C9CD600D6D6EF00BDBDE7004A4ACE003131F700D6D6
      FF004A4AEF000000E7000000D600F7F7FF00ADCEE70052C6FF0052C6FF00FFFF
      FF0084DEFF0042BDFF0063ADE700A5CEE7008CBDE7004AADE70063C6FF00EFF7
      FF00ADDEFF0018A5FF001894F700F7FFFF000000000000000000FFE7C600FFF7
      DE00FFFFE700FFFFE700FFFFE700FFF7E700F7F7EF00D6B59C00E7A55A00E7A5
      5A00DEC6B500E7D6CE00FFFFFF0000000000CE9C7300F7C67B00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFEFD600FFE7BD00FFE7C600FFFFEF00FFFFFF00FFFF
      FF00FFFFFF00EFC69400D6944200FFF7F7006363E7003939EF00FFFFFF00FFFF
      FF00FFFFFF00CECEFF006363FF005252FF005A5AFF009C9CFF00FFFFFF00FFFF
      FF00FFFFFF002929EF000000DE00F7F7FF00ADCEE70052CEFF00FFFFFF00FFFF
      FF00FFFFFF00F7FFFF00A5E7FF0084DEFF008CDEFF00CEEFFF00FFFFFF00FFFF
      FF00FFFFFF0063BDFF001894F700F7FFFF000000000000000000FFE7C600FFFF
      E700FFFFEF00FFFFEF00FFFFEF00FFFFEF00FFFFEF00F7EFD600F7EFD600F7EF
      D600F7E7CE00F7EFE7000000000000000000CE9C7300F7CE9400F7C68400FFF7
      EF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00F7CE9C00F7C68C00D69C4A00FFF7F700636BE7005252F7004A4AD600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00A5A5DE000808F7000000DE00F7F7FF00ADD6E7006BD6FF0052BDF700F7FF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0094C6E70052C6FF00219CF700F7FFFF000000000000000000FFEFCE00FFFF
      EF00FFFFEF00FFFFEF00FFFFEF00FFFFEF00FFFFEF00FFFFEF00FFFFEF00FFFF
      EF00FFF7E700F7EFE7000000000000000000CE9C7300FFD6A500FFD6A500FFDE
      A500F7CE9400FFF7E700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFE7BD00F7CE
      9C00FFDEB500FFDEB500DEAD6300FFF7F7006B6BE7006363FF006363FF004A4A
      EF00ADADDE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E7E7F7005A5A
      D6008484FF008C8CFF000000DE00F7F7FF00ADD6E7007BDEFF0084E7FF007BDE
      FF007BB5E700F7F7FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C6DEEF0063BD
      EF009CDEFF009CDEFF0031A5F700F7FFFF000000000000000000FFEFCE00FFFF
      EF00FFFFF700FFFFF700FFFFF700FFFFF700FFFFF700FFF7EF00F7EFE700F7F7
      E700F7EFDE00EFE7DE00FFFFFF0000000000CE9C7300FFDEAD00FFDEAD00FFE7
      B500FFE7BD00FFEFC600FFE7B500FFDEAD00FFE7B500FFE7BD00FFEFC600FFE7
      BD00FFE7BD00FFE7BD00EFCE9400FFF7F7006B6BE7007373FF006B6BFF007373
      FF007B7BFF006B6BF7005A5ADE006363D6005A5AD6006363EF008C8CFF008C8C
      FF008C8CFF009494FF003131E700F7F7FF00ADD6E7008CE7FF008CE7FF0094EF
      FF0094EFFF0094EFFF0073CEF7006BC6EF006BC6EF008CDEFF00A5EFFF00A5E7
      FF00A5E7FF00A5E7FF0073C6FF00F7FFFF000000000000000000FFEFD600FFFF
      F700FFFFF700FFFFF700FFFFF700FFFFF700FFFFF700EFE7D600CEBDA500CEBD
      A500DECEB500E7E7D600FFFFFF0000000000D6A58400FFE7BD00FFE7BD00FFEF
      C600FFEFCE00FFEFCE00FFEFD600FFF7D600FFEFD600FFEFD600FFEFCE00FFEF
      CE00FFEFC600FFE7C600FFE7BD00FFFFFF00737BE7007B7BFF007B7BFF008484
      FF008C8CFF009494FF009C9CFF009C9CFF009C9CFF009C9CFF009C9CFF009C9C
      FF009C9CFF009C9CFF006363F700FFFFFF00B5D6E7009CEFFF009CEFFF009CEF
      FF00A5F7FF00A5F7FF00A5EFFF00A5EFFF00ADEFFF00ADEFFF00ADEFFF00ADEF
      FF00ADE7FF00B5E7FF00A5DEFF00FFFFFF000000000000000000FFEFD600FFFF
      F700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFF700DED6C600F7CE9C00D6B5
      7B00C6A57300FFFFF7000000000000000000FFF7F700FFF7D600FFEFCE00FFEF
      D600FFF7D600FFF7DE00FFF7DE00FFF7DE00FFF7DE00FFF7DE00FFF7D600FFEF
      D600FFEFD600FFEFD600E7BD9400FFFFFF00DEDEF7009C9CFF009494FF009C9C
      FF00A5A5FF00ADADFF00ADADFF00ADADFF00B5B5FF00B5B5FF00B5B5FF00B5B5
      FF00ADADFF00ADADFF007B84F700FFFFFF00FFFFFF00B5F7FF00A5F7FF00ADF7
      FF00ADF7FF00ADF7FF00B5F7FF00B5F7FF00B5F7FF00B5F7FF00B5EFFF00BDEF
      FF00BDEFFF00BDEFFF0084CEEF00FFFFFF000000000000000000FFE7D600FFF7
      EF00FFFFF700FFFFF700FFFFF700FFFFF700FFF7EF00E7DECE00FFEFCE00D6BD
      8C00F7F7EF00FFFFFF000000000000000000FFFFFF00F7EFEF00EFC6A500F7D6
      AD00F7D6B500F7D6B500F7D6AD00F7D6AD00F7D6AD00F7CEAD00F7CEAD00EFCE
      A500EFCEA500E7C6A5000000000000000000FFFFFF00B5BDEF00BDC6FF00CECE
      FF00CECEFF00CED6FF00CED6FF00CED6FF00CED6FF00CECEFF00CECEFF00C6CE
      FF00C6C6FF00848CF7000000000000000000FFFFFF00F7F7FF009CDEEF00ADE7
      F700ADE7F700ADE7F700ADE7F700A5E7F700ADE7F700A5E7F700A5E7F700A5DE
      F7009CDEF7008CCEE70000000000000000000000000000000000EFDEBD00EFDE
      BD00EFDEC600EFDEC600EFDEC600EFDEC600EFDEC600E7D6BD00D6BD8C00F7F7
      F700FFFFFF000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF009C9C9C008484
      8400848484008484840084848400848484008484840084848400848484008484
      8400848484008C8C8C00E7E7E700000000000000000000000000FFFFFF00FFFF
      FF00DEDEDE00ADADAD00DEDEDE00EFEFEF00E7E7E700BDBDBD00BDBDBD00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00E7E7E700ADADAD00E7E7E700F7F7F700F7F7F700D6D6D600A5A5A500F7F7
      F700FFFFFF000000000000000000000000000000000000000000D6944A00D694
      5200D6945200D6945200D6945200D6945200D6945200D6945200D6945200D694
      5200D6945200F7EFE700000000000000000000000000F7F7F700CECECE00E7E7
      E700DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDE
      DE00DEDEDE00DEDEDE00C6C6C6000000000000000000FFFFFF00FFFFFF00ADAD
      AD00F7F7F700DEDEDE00E7E7E700E7E7E700E7E7E700E7E7E700E7E7E700DEDE
      DE00E7E7E700FFFFFF0000000000000000000000000000000000FFFFFF00A5A5
      A500F7F7F700DEDEDE00E7E7E700E7E7E700E7E7E700E7E7E700DEDEDE00F7F7
      F700BDBDBD00FFFFFF0000000000000000000000000000000000DEA56300D6A5
      6B00D6A56B00DEAD7300DEAD7300E7AD7300E7AD7300E7AD7300E7AD7300E7AD
      7300E7AD6B00F7EFE700000000000000000000000000F7F7F700D6D6D600F7F7
      F700EFEFEF00D6D6D600D6D6D600CECECE00D6D6D600D6D6D600D6D6D600D6D6
      D600D6D6D600D6D6D600C6C6C6000000000000000000FFFFFF00CECECE00E7E7
      E700E7E7E700E7E7E700E7E7E700E7E7E700E7E7E700E7E7E700E7E7E700E7E7
      E700F7F7F700E7E7E700FFFFFF000000000000000000FFFFFF00B5B5B500E7E7
      E700E7E7E700E7E7E700E7E7E700E7E7E700E7E7E700E7E7E700E7E7E700E7E7
      E700F7F7F700B5B5B500FFFFFF00000000000000000000000000E7B57B005252
      4A002939390052A5BD00738C8C00BD9C7300E7BD8C00EFBD8C00EFBD8C00EFBD
      8C00EFBD8400F7EFE700000000000000000000000000F7F7F700D6D6D600F7F7
      F700EFEFEF00D6D6D600D6D6D600ADADAD00D6D6D600D6D6D600D6D6D600D6BD
      B500CE737300BD736B0094848400EFEFEF00FFFFFF00ADADAD00E7E7E700E7E7
      E700EFEFEF00E7E7E700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEF
      EF00E7E7E700E7E7E700FFFFFF0000000000FFFFFF00ADADAD00EFEFEF00E7E7
      E700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEF
      EF00EFEFEF00F7F7F700EFEFEF00FFFFFF000000000000000000EFC68C00B5A5
      94005AC6DE0052DEFF0052DEFF00736B6300CEAD8C00EFD6A500F7D6A500F7D6
      A500F7CE9C00F7EFE700000000000000000000000000F7F7F700D6D6D600F7F7
      F700EFEFEF00D6D6D600D6D6D600CECECE00CECECE00D6D6D600D6BDBD00C673
      6B00BD6B6B00BD6B6B00C6736B00948C8C00F7F7F700F7F7F700EFEFEF00EFEF
      EF00EFEFEF005252520042424200EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEF
      EF00EFEFEF00EFEFEF00B5B5B500FFFFFF00FFFFFF00EFEFEF00EFEFEF00EFEF
      EF00F7F7F7007373730073737300F7F7F700F7F7F7007B7B7B0073737300F7F7
      F700EFEFEF00EFEFEF00BDBDBD00FFFFFF000000000000000000F7D6A500E7CE
      AD007BE7FF007BEFFF0073E7FF00102121006B635A00D6C6A500F7E7BD00FFE7
      BD00FFDEB500F7EFE700000000000000000000000000F7F7F700D6D6D600F7F7
      F700EFEFEF00D6D6D600D6D6D600BDBDBD00BDBDBD00D6D6D600DE949400D69C
      9C00CE8C8400CE847B00CE8C8400BD737300ADADAD00EFEFEF00EFEFEF00EFEF
      EF00EFEFEF005A5A5A0031313100292929006B6B6B00FFFFFF00EFEFEF00EFEF
      EF00EFEFEF00EFEFEF00D6D6D600FFFFFF00C6C6C600EFEFEF00EFEFEF00EFEF
      EF00F7F7F7002929290029292900F7F7F700FFFFFF002929290029292900F7F7
      F700EFEFEF00EFEFEF00F7F7F700FFFFFF000000000000000000FFDEB500FFEF
      CE0084E7FF007BDEEF0094F7FF005AEFFF00082931006B5A5200E7D6BD00FFEF
      D600FFEFCE00F7EFE700000000000000000000000000F7F7F700D6D6D600F7F7
      F700EFEFEF00D6D6D600D6D6D600CECECE00E7E7E700D6D6D600EFB5B500DE9C
      9400DE949400D6949400EFD6D600C6847B00BDBDBD00EFEFEF00EFEFEF00EFEF
      EF00F7F7F7005A5A5A0039393900393939003939390029292900A5A5A500FFFF
      FF00EFEFEF00EFEFEF00EFEFEF0000000000ADADAD00EFEFEF00EFEFEF00EFEF
      EF00FFFFFF002929290029292900FFFFFF00FFFFFF002929290029292900F7F7
      F700EFEFEF00EFEFEF00EFEFEF00DEDEDE000000000000000000FFE7BD00FFF7
      D600EFE7CE005A5252005A84840094FFFF005AEFFF0010394200635A5200E7DE
      C600FFEFD600F7EFE700000000000000000000000000F7F7F700DEDEDE00F7F7
      F700EFEFEF00DEDEDE00DEDEDE00DEDEDE00E7E7E700DEDEDE00DEDEDE00D68C
      8400CE7B7B00CE7B7B00E78C8400CECECE00CECECE00F7F7F700EFEFEF00EFEF
      EF00F7F7F7006363630042424200424242004242420039393900393939002121
      2100FFFFFF00F7F7F700F7F7F700FFFFFF00B5B5B500F7F7F700EFEFEF00EFEF
      EF00FFFFFF003131310031313100FFFFFF00FFFFFF003131310031313100F7F7
      F700EFEFEF00EFEFEF00F7F7F700D6D6D6000000000000000000FFE7C600FFF7
      DE00FFFFE700F7F7DE006B6363004A6B6B009CFFFF0063EFFF00104A5A005A5A
      5200EFE7CE00F7EFE700000000000000000000000000F7F7F700E7E7E700F7F7
      F700EFEFEF00E7E7E700E7E7E700BDBDBD00DEDEDE00C6C6C600D6D6D600E7E7
      E700E7CECE00EFC6C600BDBDBD00FFFFFF00C6C6C600F7F7F700F7F7F700F7F7
      F700F7F7F7006B6B6B0052525200525252004A4A4A004242420084848400FFFF
      FF00F7F7F700F7F7F700F7F7F70000000000B5B5B500F7F7F700F7F7F700F7F7
      F700FFFFFF004242420042424200FFFFFF00FFFFFF004242420039393900F7F7
      F700F7F7F700F7F7F700F7F7F700E7E7E7000000000000000000FFE7C600FFFF
      E700FFFFEF00FFFFEF00FFF7E7007B7B7300395252009CFFFF009CCED6003939
      3900A5A5B500F7EFE700000000000000000000000000F7F7F700E7E7E700FFFF
      FF00EFEFEF00BDBDBD00ADADAD00CECECE00C6C6C600C6C6C600DEDEDE009C9C
      9C00B5B5B500EFEFEF00C6C6C60000000000B5B5B500F7F7F700F7F7F700F7F7
      F700FFFFFF00ADADAD00949494008C8C8C009C9C9C00FFFFFF00FFFFFF00FFFF
      FF00F7F7F700F7F7F700E7E7E70000000000CECECE00F7F7F700F7F7F700F7F7
      F700FFFFFF009C9C9C008C8C8C00FFFFFF00FFFFFF00949494009C9C9C00FFFF
      FF00FFFFFF00F7F7F700FFFFFF00000000000000000000000000FFEFCE00FFFF
      EF00FFFFEF00FFFFEF00FFFFEF00FFFFEF009C9C94008484840094949C00A59C
      CE00AD9CBD00F7EFE700000000000000000000000000F7F7F700E7E7E700FFFF
      FF00F7F7F700E7E7E700E7E7E700DEDEDE00CECECE00D6D6D600C6C6C600ADAD
      AD00ADA5A500E7E7E700CECECE0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00BDBDBD00B5B5B500F7F7F700FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00BDBDBD00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00B5B5B500B5B5B500FFFFFF00FFFFFF00B5B5B500B5B5B500FFFF
      FF00FFFFFF00FFFFFF00CECECE00FFFFFF000000000000000000FFEFCE00FFFF
      EF00FFFFF700FFFFF700FFFFF700FFFFF700FFFFF700C6C6C600947BB500846B
      B500E7DECE00EFE7DE00FFFFFF000000000000000000F7F7F700E7E7E700FFFF
      FF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00F78C8400F78C
      8400F78C8400AD848400FFFFFF0000000000FFFFFF00BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00F7F7F700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F7F7F7000000000000000000FFFFFF00BDBDBD00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F7F7F700000000000000000000000000FFEFD600FFFF
      F700FFFFF700FFFFF700FFFFF700FFFFF700FFFFF700EFE7D600CEBDA500CEBD
      A500DECEB500E7DED600FFFFFF000000000000000000F7F7F700E7E7E700FFFF
      FF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00FF9C9400FF94
      9400AD8C8C00FFFFFF0000000000000000000000000000000000E7E7E700FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F7F7F70000000000000000000000000000000000D6D6D600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C6C6C600FFFFFF00000000000000000000000000FFEFD600FFFF
      F700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFF700DED6C600F7CE9C00D6B5
      7B00C6A57300FFFFF700000000000000000000000000F7F7F700E7E7E700FFFF
      FF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00FFCECE00AD9C
      9C00FFFFFF00000000000000000000000000000000000000000000000000CECE
      CE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F7F7
      F700F7F7F700FFFFFF000000000000000000000000000000000000000000C6C6
      C600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00CECECE00FFFFFF0000000000000000000000000000000000FFE7D600FFF7
      EF00FFFFF700FFFFF700FFFFF700FFFFF700FFF7EF00E7DECE00FFEFCE00D6BD
      8C00F7F7EF00FFFFFF00000000000000000000000000F7F7F700E7E7E700E7E7
      E700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00ADA5A500FFFF
      FF0000000000FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000EFEFEF00CECECE00F7F7F700FFFFFF00FFFFFF00D6D6D600CECECE000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00F7F7F700CECECE00FFFFFF00FFFFFF00FFFFFF00EFEFEF00C6C6C6000000
      0000FFFFFF000000000000000000000000000000000000000000EFDEBD00EFDE
      BD00EFDEC600EFDEC600EFDEC600EFDEC600EFDEC600E7D6BD00D6BD8C00F7F7
      F700FFFFFF000000000000000000000000000000000000000000FFFFFF00F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700FFFFFF000000
      0000000000000000000000000000000000000000000008080800000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFF7F700FFF7F700FFF7F700FFFFFF00F7F7EF00C6D6
      BD00C6D6BD00FFFFFF00000000000000000000000000FFFFFF009C9C9C008484
      8400848484008484840084848400848484008484840084848400848484008484
      8400848484008C8C8C00E7E7E700000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000E7E7E700DEDEDE0000000000DEE7E700F7B55A00A573
      3900211810000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      F700EFDED600E7C6BD00DEB5A500D6AD9400DEAD9400DEBDB5009CA57B000094
      210000941800FFFFFF00000000000000000000000000F7F7F700CECECE00E7E7
      E700DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDE
      DE00DEDEDE00DEDEDE00C6C6C6000000000000000000EFEFEF00A5A5A5008484
      84007B7B7B0073737300ADADAD00EFEFEF000000000000000000F7F7F700ADA5
      A500A5846B00E7A57300DEAD7300B5B5B50000000000D6DEDE00F7C69C00FFD6
      AD00FFD69C00FFBD6B00AD7B3900292110000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000F7EFEF00E7D6
      CE00E79C6B00FFCE9C00FFDEBD00FFE7CE00FFDEC600FFD6AD00AD94420000A5
      290000A52900FFFFFF00FFFFFF000000000000000000F7F7F700D6D6D600FFF7
      EF00F7EFE700D6D6D600D6D6D600EFEFEF00D6D6D600DEDEDE00D6D6D600D6D6
      D600D6D6D600D6D6D600C6C6C6000000000000000000CECECE00525A52003939
      3900393939004242420039393900A5A5A5009C847300DE9C7300FFC68C00FFDE
      9C00FFD69C00FFBD8400DEAD7300B5B5B50000000000D6D6DE00EFBD8C00EFBD
      8C00EFBD8C00D6B58C00B57B5A00B5947300FFC67300BD8C4200312110000000
      00000000000000000000000000000000000000000000FFF7EF00EFDED600F79C
      4A00FFCEA500FFD6B500FFE7CE00FFEFDE00089C290010A5310010AD390000B5
      390000B53900089C29001094290063AD630000000000F7F7F700D6D6D600FFF7
      EF00F7EFE700D6D6D600FFFFFF00FFFFFF00FFFFFF00FFFFFF00F7F7F700D6BD
      A500DE8C4200D6843900948C7B00EFEFEF00FFFFFF00737B7B004A4A4A006363
      63006B6B6B009C847300635A5A004A4A4A00FFDE9C00FFD69C00FFC68C00FFD6
      9C00FFD69C00FFC68C00D6B58400B5B5BD0008080800D6D6DE00EFC68C00EFC6
      8C00EFBD8C00CEAD8400FFB57B00FFBD7B00FFA56300AD6B3900B5946B00FFCE
      8400C68C4A00392910000000000000000000FFFFFF00F7EFEF00E7842900FFB5
      7B00FFB57B00FFCEA500FFDEBD00FFE7CE00E7D6B50000D6520000CE4A0000C6
      4A0000BD420000B5390010B542000000000000000000F7F7F700D6D6D600FFF7
      EF00F7EFE700EFEFEF00FFFFFF00FFFFFF00CECECE00D6D6D600F7E7CE00D684
      3100D6843900D67B2900D6843100948C8400B5B5B50063636300736B6B004239
      3900423939005A52520039393100423939008C7B6300FFD69C00FFDEA500FFEF
      B500FFE7AD00FFD6A500CEB58C00BDBDBD0018181800D6D6D600F7C68400EFC6
      8C00EFC68C00CEAD7B00FFDE9C00FFF7B500FFE79C00FFBD7300EF843900EFC6
      9C00F7CEA500FFD6AD00BD94630000000000FFFFFF00D69C7B00FF944200FF94
      3900FFBD8C00FFC69C00FFD6AD00FFDEBD00FFD6BD00ADB5730042EF8C0042E7
      840042DE84005AE79400F7F7EF000000000000000000F7F7F700D6D6D600FFF7
      EF00EFEFE700EFEFEF00FFFFFF00DEDEDE00D6D6D600D6D6D600EFA56300D684
      3100E7B58C00F7D6B500D6843100CE8C4A0084848400636363006B636300847B
      7B0094948C00736B6B007B7B7B0031313100736B6300FFE7AD00FFEFBD00FFF7
      C600FFEFBD00FFE7B500C6AD8C00BDBDBD0021212100D6D6DE00F7C68400EFC6
      8400EFC68C00D6AD7B00FFFFCE0094521000AD7B3900FFFFB500F7AD6B00FFAD
      0000E7BD9400EFBD9400B58C63000000000000000000D66B1800E77B2900EF84
      3100FFC69C00FFBD8C00FFC69C00FFCEA500FFD6B500FFD6BD008CC684007BF7
      AD0073F7AD00AD732100D6A57B000000000000000000F7F7F700D6D6D600FFF7
      EF00F7EFE700CECECE00FFFFFF00EFEFEF00D6D6D600D6D6D600FFC68C00E794
      4200F7D6B500F7D6B500E7944200D6945200ADADAD008C8484005A5A5A00C6C6
      C60031292900393931008C8C840039393100AD9C8400FFE7BD00FFF7CE00FFFF
      D600FFF7CE00FFEFBD00ADAD9400BDBDBD0029292900DEDEDE00EFBD7B00EFC6
      8400EFC68400D6AD7B00FFDEA500945218009452100084390000FFCE7B00DEB5
      8400F7A52100EFC69400B59463000000000000000000D6631000D66B1800E773
      2100FFE7CE00FFCEAD00FFDEC600FFEFDE00FFF7E700FFEFE700FFE7D600ADEF
      C6009CB56B00CE631000C66318000000000000000000F7F7F700DEDEDE00FFF7
      F700F7EFE700CECECE00EFEFEF00EFEFEF00DEDEDE00DEDEDE00FFFFF700EFA5
      5200E7944200E7944200F7A55200CEC6C600B5B5B500BDBDBD006B6B6300CECE
      CE00393939008C8C840073736B0042424200FFF7CE00FFF7C600FFFFD600FFFF
      DE00FFFFD600FFF7CE00B5A59400BDBDBD0042424200E7E7EF00DEAD6B00EFC6
      7B00EFC68400D6AD7300F7BD8400FFE7AD00F7EFCE00EFDEAD00FFC67B00CE94
      8C00FF4A0000EFC69400BD94630000000000EFEFEF00DE731800EF944A00F794
      4A00FFEFE700FFDEC600FFD6B500FFDEBD00FFE7D600FFF7EF00FFF7EF00FFE7
      CE00FFCE9C00CE631000CE6308000000000000000000F7F7F700E7E7E700FFFF
      F700F7EFEF00EFEFEF00F7F7F700FFFFFF00E7E7E700E7E7E700E7E7E700FFFF
      F700FFD6B500F7CEAD00BDB5B500FFFFFF00F7F7F700C6C6C600A57B63009C94
      8C00C6BDBD008C84840042424200D6C6A500FFEFC600FFF7CE00FFFFDE00FFFF
      E700FFFFDE00FFFFDE00A5A59400BDBDBD004A4A4A00EFEFEF00C69C6B00EFB5
      7B00EFBD7B00D6AD7300D68C6300FFB57B00FFBD8400FFB57300BD7B4A00FF84
      1800E7522100F7C68C00BD94630000000000F7F7F700F79C4A00FF943900F7B5
      8400FFD6AD00FFD6B500FFD6AD00FFDEBD00FFE7D600FFEFE700FFEFDE00FFD6
      B500FFA56300D66B1000C65A08000000000000000000F7F7F700E7E7E700FFFF
      F700F7F7EF00E7E7E700E7E7E700EFEFEF00F7F7F700F7F7F700FFFFFF00EFEF
      EF00EFEFEF00EFEFEF00C6C6C6000000000000000000F7D6AD00DEE7E7005252
      52004A42420084847B00CEB5A500FFE7C600FFEFCE00FFFFD600FFFFEF00FFFF
      EF00FFFFE700FFFFE7009C9C9C00BDBDBD005A5A5A00EFEFEF00EFEFEF00DEDE
      D600C69C7300DE9C6300CE9C63004231210042291800AD6B3900B5632900F7CE
      8C00F7C68400EFC68400C69463000000000000000000FF8C3900FFAD6B00FFCE
      A500FFCEA500FFF7EF00FFD6AD00FFD6AD00FFDEBD00FFDEC600FFDEBD00FFC6
      9C00FFB57B00E77B2900B57342000000000000000000F7F7F700E7E7E700FFFF
      FF00F7F7EF00EFEFEF00EFEFEF00EFEFEF00E7E7E700DEDEDE00DEDEDE00E7E7
      E700E7E7E700E7E7E700CECECE000000000000000000F7CEA500EFBD9C00EFD6
      BD00E7CEBD00EFC6A500FFD6AD00FFE7C600FFEFCE00FFFFDE00FFFFEF00FFFF
      EF00FFFFEF00FFFFEF00ADADAD00BDBDBD006B6B6B00EFEFEF00EFEFEF00EFEF
      EF00EFEFEF00EFF7F700DED6CE00CEA57300F7BD7B00CE9C63007B634200F7BD
      7B00EFC67B00EFC68400DEA56B000000000000000000D68C4A00FFCEA500FFDE
      C600FFD6AD00FFE7CE00FFD6B500FFCEAD00FFCEA500FFCEAD00FFC69C00FFB5
      7300FFC69400F78C3900E7E7DE000000000000000000F7F7F700E7E7E700FFFF
      FF00F7F7EF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00F7A55200F7A5
      5200F7A55200B5947300FFFFFF000000000000000000F7CEA500EFBD9C00EFBD
      9400EFBD9400EFC6A500FFD6B500FFE7C600FFF7D600FFFFE700FFFFF700FFFF
      FF00F7F7EF00C6BDB500DEDEDE00BDBDBD006B6B6B00EFEFEF00EFEFEF00EFEF
      EF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFF700CE9C6B00E7A56B00E7AD
      6B00EFB57300EFB57300E7B56B000000000000000000FFFFFF00FFBD8C00FFF7
      EF00FFD6B500FFD6B500FFFFFF00FFDEC600FFCEA500FFC69400FFBD8400FFBD
      8400FFC69C00DE7B3100000000000000000000000000F7F7F700E7E7E700FFFF
      FF00F7EFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00FFB56300FFAD
      6300B5947300FFFFFF00000000000000000000000000F7CEA500EFBD9C00EFBD
      9C00EFBD9C00F7CEAD00FFDEBD00FFFFD600EFE7CE00C6BDAD00B5ADA500BDBD
      BD00CECECE00D6D6D600EFEFEF009C9C9C00000000006B6B6B00D6D6D600FFFF
      FF00EFEFEF00EFEFEF00F7F7F700F7F7F700EFEFEF00CEBDAD00CE8C5A00DE94
      5A00DE9C6300DEA56B00DE9C5A00000000000000000000000000E7EFCE00FFE7
      D600FFE7D600FFD6B500FFEFDE00FFFFF700FFC69C00FFC69400FFBD8400FFE7
      D600FF94420000000000000000000000000000000000F7F7F700E7E7E700FFFF
      FF00EFEFE700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00FFD6B500B5A5
      8C00FFFFFF00000000000000000000000000FFFFFF00F7D6AD00EFC6A500F7CE
      AD00EFBD9C00C6AD8C00ADA59400ADADAD00DEDEDE00D6D6D600DEDEDE00E7E7
      E700DEDEDE00DEDEDE00FFFFFF00F7F7F7000000000000000000000000000000
      0000101010008C8C8C001010100000000000101010009C9C9C00FFFFFF00E7E7
      DE00C69C7300CE844A00D68C520000000000000000000000000000000000E7EF
      DE00FFCEA500FFE7D600FFD6B500FFCEAD00FFE7D600FFCE9C00FFE7CE00EF9C
      5A000000000000000000000000000000000000000000F7F7F700E7E7E700E7E7
      E700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00BDA59400FFFF
      FF0000000000FFFFFF00FFFFFF0000000000FFFFF700BDA58C00A5948C00B5BD
      BD00CECED600DEDEDE00F7F7F700E7E7E700ADADAD00B5B5B500EFEFEF00F7F7
      F700FFFFFF00F7F7F700ADADAD00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000808
      080094949400DEDEE70000000000000000000000000000000000000000000000
      000000000000D6CEBD00D6A57B00E7AD7B00DEA57300CEAD8400F7FFF7000000
      0000000000000000000000000000000000000000000000000000FFFFFF00F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700FFFFFF000000
      0000000000000000000000000000000000000000000000000000DEDEDE00C6C6
      C6009C9C9C00C6C6C60000000000000000000000000000000000B5B5B500B5B5
      B500F7F7F7000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000DEDEF700DEDE
      F700DEDEF700F7F7FF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00F7F7F700FFFFFF00FFFFFF00FFFFFF000000
      000000000000000000000000000000000000FFFFFF00F7F7F700EFEFEF00E7E7
      E700DEDEDE00DEDEDE00DEDEDE00DEDEDE00E7E7E7006B6BC6001010C6001010
      C6001010C6001818B500F7F7FF0000000000000000000000000000000000D68C
      730000000000F7F7F700FFFFFF0000000000FFFFFF00FFFFFF00F7F7F700EFEF
      EF00EFD6D6000000000000000000000000000000000000000000000000000000
      0000BDADA500BD4A0000E7730000E76B0000E76B0000D6630000A5522900FFFF
      FF0000000000000000000000000000000000EFEFEF00D6D6D600C6C6C600CECE
      CE0073737300BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00ADADAD00A5A5
      A500C6C6C600CECECE00E7E7E700FFFFFF006B6B6B0073737300848484008C8C
      8C009494940094949400949494008C8C8C00393994000000CE000000CE000000
      D6000000CE000000CE001010B500F7F7FF00000000000000000000000000E7A5
      9400FFB55200AD736300CECECE00BDBDBD00BDBDBD00BDBDBD00DE6B4200FFBD
      4A0000000000000000000000000000000000000000000000000000000000B54A
      0000D6630800CE5A0800CE5A0800CE5A0800CE5A0800CE5A0800CE520000DE73
      0000B58C7B00000000000000000000000000EFEFEF00E7E7E700E7E7E700EFEF
      EF00C6C6C600BDBDBD00DEDEDE00DEDEDE00DEDEDE00F7F7F700ADADAD00EFEF
      EF00DEDEDE00E7E7E700EFEFEF00FFFFFF00525252007373730094949400BDBD
      BD00DEDEDE00F7F7F700DEDEDE00BDBDBD000808D6000000DE000000DE000000
      DE000000DE000000DE000000D600A5A5E70000000000FFFFFF00EFEFEF00C6B5
      B500FFB55A00FFD69C00FFB58400A58C8C00B5635200FFDEAD00FFC68C00FFAD
      4A00F7F7F700F7F7F70000000000000000000000000000000000C65A0800CE63
      0800D6631000D66B1000D66B1000D66B1000D66B1000D66B1000CE630800CE63
      0800DE6B0800AD8C7B0000000000000000000000000000000000000000000000
      00009C9C9C00C6C6C6000000000000000000000000009C9C9C009C9C9C000000
      000000000000000000000000000000000000636363008C8C8C00A5A5A500BDBD
      BD00E7E7E700F7F7F700DEDEDE00C6C6C6000808E700ADADFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000E700A5A5E70000000000F7F7F700EFEFEF00EFEF
      EF00FFAD5200FFBD8400FFD6AD00FFF7DE00FFEFD600FFD6A500FFB57300FF84
      4200F7F7F700EFEFEF00FFFFFF000000000000000000A5522100D66B1000D673
      1000D6731800D67B1800D67B1800D67B1800E7A52100DEA55A00D6731000D66B
      1000D66B1000DE730800FFFFFF00000000000000000000000000000000000000
      000000000000C6C6C600C6C6C6000000000000000000C6C6C600EFEFEF000000
      000000000000000000000000000000000000636363008C8C8C00A5A5A500BDBD
      BD00EFEFEF00F7F7F700DEDEDE00C6C6C6003131F7001010F7000000FF000000
      FF000000FF000808F7002929F700A5A5E7000000000000000000000000000000
      0000FF9C5200FFA56300FFBD8400FFC69C00FFC69C00FFB58400FF9C5200FF8C
      63000000000000000000000000000000000000000000DE7B1000D67B1800DE7B
      1800DE842100DE8C2100DE8C2100E7AD3900DEDEDE00DEDEDE00DE842100D67B
      1800D6731800D66B1000A5522900000000000000000000000000000000000000
      000000000000C6C6C600D6D6D600000000009C9C9C008C8C8C00000000000000
      000000000000000000000000000000000000525252007B7B7B009C9C9C00B5B5
      B500C6C6C600CECECE00C6C6C600B5B5B5004A4AB5005252FF005252FF005A5A
      FF005252FF004A4AFF005A5AFF00FFFFFF000000000000000000000000000000
      0000F7945A00FF843900FF945200FF9C6300FF9C5A00FF944A00FF843100EF8C
      730000000000000000000000000000000000B5948400D67B1800DE842100DE8C
      2100DE942900E7A53100E7BD7300E7E7E700E7E7E700E7E7E700DE942900DE8C
      2100DE841800D67B1800CE630800000000000000000000000000000000000000
      00000000000000000000BDBDBD008C8C8C00BDBDBD00FFFFFF00000000000000
      000000000000000000000000000000000000525252007B7B7B009C9C9C00BDBD
      BD00E7E7E700FFFFFF00E7E7E700C6C6C600A5A5A5004242AD00A5A5FF009C9C
      FF009C9CFF008484FF000000000000000000000000000000000000000000F77B
      4200FF6B1000FF6B1800FF6B1800FF6B2100FF6B1800FF6B1800FF6B1000FF7B
      2900E77B6300000000000000000000000000AD522900DE8C2100DE942900E79C
      2900EFAD3900E7D6B500EFEFEF00EFEFEF00EFEFEF00EFEFEF00E7A53100E79C
      2900DE942100DE842100DE7B1800000000000000000000000000000000000000
      00000000000000000000DEDEDE00BDBDBD008484840000000000000000000000
      0000000000000000000000000000000000006363630094949400ADADAD00C6C6
      C600EFEFEF00FFFFFF00E7E7E700CECECE00B5B5B5009494940063636B00F7F7
      FF00EFEFF7000000000000000000000000000000000000000000EF5A1800FF6B
      2900FF845200FF945A00FF945A00FF945A00FF945A00FF945A00FF8C5A00FF7B
      3900FF631000E78C73000000000000000000AD4A1000DE942900E79C2900E7AD
      3100DE9C2900F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700EFAD3100E7A5
      3100E79C2900DE942100DE842100000000000000000000000000000000000000
      000000000000000000009C9C9C00A5A5A500ADADAD0000000000000000000000
      0000000000000000000000000000000000006363630094949400ADADAD00C6C6
      C600F7F7F700FFFFFF00E7E7E700CECECE00B5B5B500949494006B6B6B000000
      00000000000000000000000000000000000000000000F7A58400FFCEBD00FFC6
      AD00FFBDA500FFBD9C00FFBD9C00FFBD9C00FFBD9C00FFBD9C00FFBDA500FFC6
      A500FFC6AD00FFCEB500E78C730000000000A5634A00E7A53900EFAD4200EFB5
      4200EFBD4200CE842900FFFFFF00FFFFFF00FFFFFF00FFFFFF00EFBD3900EFB5
      3900E7AD3900E7A53900DE8C3100000000000000000000000000F7F7FF00A5A5
      EF00000000005252FF001818BD000000000073739C000000D60000000000D6D6
      FF00B5B5EF00000000000000000000000000525252007B7B7B0094949400ADAD
      AD00C6C6C600CECECE00C6C6C600ADADAD009C9C9C007B7B7B005A5A5A000000
      0000000000000000000000000000000000000000000000000000F7D6CE00EFA5
      9400E7735200F7BDAD00FFDED600FFDED600FFDED600FFEFE700EF947300DE73
      5200EFAD9C00F7DEDE000000000000000000D6CECE00EFC67300EFC66300F7CE
      6300F7D66B00F7DE6B00D6A54A00FFF7EF00FFFFFF00FFFFFF00F7D66B00F7CE
      6300EFC66300EFB55A00BD6329000000000000000000ADADF7000000D6006B6B
      FF001818EF000000DE00DEDEF70000000000000000000000D6000000EF002929
      FF004242EF000808D60000000000000000006363630094949400B5B5B500D6D6
      D600F7F7F700FFFFFF00F7F7F700D6D6D600B5B5B5008C8C8C00636363000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFF7EF00FFF7F700F7AD9C00000000000000
      00000000000000000000000000000000000000000000CE8C6300F7D68400F7DE
      8400FFE78C00FFEF8C00FFEF9400EFCE7B00E7CEBD00FFFFFF00FFE78C00F7DE
      8400F7D68400F7D69400B59C940000000000000000000000DE00000000000000
      00005A5AEF002121EF00000000000000000000000000EFEFFF000000E7000000
      0000000000000000B500FFFFFF00000000007B7B7B00ADADAD00CECECE00E7E7
      E700F7F7F700FFFFFF00F7F7F700DEDEDE00C6C6C600A5A5A500737373000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000DE7B5A00FFFFFF00FFFFFF00FFFFFF00000000000000
      00000000000000000000000000000000000000000000D6C6C600FFF7D600FFEF
      A500FFEFA500FFF7AD00FFF7AD00FFF7AD00FFEFA500DEAD6B00FFEFA500FFE7
      A500F7E7A500B56B42000000000000000000000000000000DE00000000000000
      00000000EF0000000000000000000000000000000000000000004242FF00B5B5
      E7000000000018189C00EFEFFF000000000084848400B5B5B500CECECE00E7E7
      E700FFFFFF00FFFFFF00F7F7F700DEDEDE00C6C6C600ADADAD00848484000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00EFAD9C0000000000000000000000
      0000000000000000000000000000000000000000000000000000B5846B00FFFF
      EF00FFF7C600FFF7C600FFF7C600FFF7C600FFF7C600FFF7C600FFF7BD00FFF7
      CE00CE947300000000000000000000000000000000006363FF001010B5003131
      E700F7F7FF000000000000000000000000000000000000000000000000002929
      FF002929AD000000FF000000000000000000C6C6C600DEDEDE00EFEFEF00F7F7
      F700FFFFFF00FFFFFF00FFFFFF00F7F7F700E7E7E700D6D6D600C6C6C6000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000EFA59400FFEFEF0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CEC6
      BD00D6A58C00FFFFFF00FFFFE700FFFFDE00FFFFDE00FFFFEF00FFF7F700A55A
      3100000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFF7F7000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000D6CECE00A56B4A00AD5A2900AD5A3100B5948400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00EFF7
      EF00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00DEE7DE00D6E7
      D600E7EFDE000000000000000000000000000000000000000000000000000000
      0000185A0000185A0000215A0000215A0000215A0000185A0000185A0000185A
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00F7F7F700EFEFEF00E7E7
      E700DEDEDE00DEDEDE00DEDEDE00DEDEDE00E7E7E700F7F7F70084B57B00007B
      0000F7F7F700000000000000000000000000FFFFFF00F7F7F700EFEFEF00E7E7
      E700DEDEDE00DEDEDE00DEDEDE00DEDEDE00E7E7E700F7F7F700089421000894
      2100088C18000000000000000000000000000000000000000000185A0000185A
      000018630000088C1800109C310021A53900189C31000894210010730800215A
      0000185A00000000000000000000000000000000000008A53100109429000894
      2100109C29000008000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000006B6B6B0073737300848484008C8C
      8C009494940094949400949494008C8C8C00848484005A735A00008408000084
      0800188C2100FFFFFF0000000000000000006B6B6B0073737300848484008C8C
      8C009494940094949400949494008C8C8C00848484007B7B7B0008A53100009C
      2100109C290000000000000000000000000000000000185A0000215A0000088C
      180021A5420010942900008C1800008C1000008C1000008C1800189C3100089C
      290018630000185A0000000000000000000000B53100009C210021AD4A0008A5
      3100009C2100009C2100736B6B009C9C9C00A5A5A5007B7B7B00101010000000
      000000000000000000000000000000000000525252007373730094949400BDBD
      BD00DEDEDE00F7F7F700DEDEDE00BDBDBD008C948C0000941800009418000094
      18000094210052AD5A00FFFFFF0000000000525252007373730094949400BDBD
      BD00DEDEDE00F7F7F700DEDEDE008CA584005A8452004A6B420010B54A0000AD
      310021AD420094BD8C0094B58C00C6D6BD0000000000215A0000009C2900109C
      3100009421000094210000942100009418000094180000942100009421000094
      1800109C290018630000185A00000000000000B5310039C663006BD69400FFFF
      FF0052CE7B0000AD2900A5BDAD00DEDEDE00EFEFEF00FFFFFF00FFFFFF00DEDE
      DE0008080800000000000000000000000000636363008C8C8C00A5A5A500BDBD
      BD00E7E7E700F7F7F700DEDEDE00BDBDBD00009C2900009C290000A5290000A5
      310000A5310000A531009CC69C0000000000636363008C8C8C00A5A5A500BDBD
      BD00E7E7E700F7F7F700DEDEDE0084A5840000C64A0000C64A0000C6420000BD
      420000B5390000AD310000A53100CEDECE00185A00000884180008A53100009C
      2100009C290000A5290063C67B00FFFFFF00FFFFFF00009C1800009C2900009C
      210000942100009C2900215A00000000000021CE630010CE5A00FFFFFF00FFFF
      FF00FFFFFF0010C65200BDDEC600DEDEDE00DEDEDE00DEDEDE00DEDEDE00EFEF
      EF00C6BDBD00000000000000000000000000636363008C8C8C00A5A5A500BDBD
      BD00EFEFEF00F7F7F700DEDEDE0029AD520018B5520008B54A0000B5420000B5
      420000BD4A0010BD5A0018C66300DEE7DE00636363008C8C8C00A5A5A500BDBD
      BD00EFEFEF00F7F7F700DEDEDE00C6C6C60052A5630010D6630008D65A0008CE
      520008C6520010C6520094C6940000000000215A000000B5390000A5290000A5
      310000AD310000AD310073D68C00FFFFFF00FFFFFF0000A5210000A5310000A5
      2900009C2900009C210010841800185A000029EF730029E77B0063EFA500FFFF
      FF0029E77B0042DE7B00BDB5B500CECECE00E7E7DE00EFEFEF00D6D6D600CECE
      CE00E7E7E700313131000000000000000000525252007B7B7B009C9C9C00B5B5
      B500C6C6C600CECECE00C6C6C6009CAD9C008C948C00637B63004ADE940039D6
      8C006BCE9400DEEFDE00DEEFDE00FFFFFF00525252007B7B7B009C9C9C00B5B5
      B500C6C6C600CECECE00C6C6C600B5B5B5009C9C9C0063CE8C004AEF94004AE7
      8C004ADE840073CE8C0000000000000000001073080000AD310000AD310000AD
      310000B5310000B539006BD69400FFFFFF00FFFFFF0000AD290000AD310000AD
      310000AD310000A5290000A52900215A0000000000006BDE9C00BDFFDE00ADF7
      CE007BF7B5009CB5A500CECECE00E7E7E700F7F7F700FFFFFF00FFFFFF00DEDE
      DE00BDBDB500525252000000000000000000525252007B7B7B009C9C9C00BDBD
      BD00E7E7E700FFFFFF00E7E7E700C6C6C600A5A5A5007B7B7B006BEFB5005AEF
      A5007BCE9400000000000000000000000000525252007B7B7B009C9C9C00BDBD
      BD00E7E7E700FFFFFF00E7E7E700C6C6C600A5A5A5007B7B7B00B5FFD60084F7
      B50094EFB500000000000000000000000000089C290000AD310000B539006BD6
      9400E7F7EF00E7F7EF00EFFFF700FFFFFF00FFFFFF00E7F7E700E7F7EF00E7F7
      EF0000AD290000AD310000AD3100215A000000000000000000006B6B6B00D6DE
      D600EFE7E700DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDED600DED6D600EFEF
      EF00B5B5AD002929290000000000000000006363630094949400ADADAD00C6C6
      C600EFEFEF00FFFFFF00E7E7E700CECECE00B5B5B50094949400ADFFE7009CFF
      D60084D69C000000000000000000000000006363630094949400ADADAD00C6C6
      C600EFEFEF00FFFFFF00E7E7E700CECECE00B5B5B50094949400636B6300DEFF
      F7000000000000000000000000000000000010AD390018BD520000BD42008CE7
      AD00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000B5310010B5420018B54A00185A00000000000000000000CECECE00D6CE
      CE00C6C6C600ADADAD00B5B5AD00CECECE00EFEFEF00FFFFFF00E7E7E700CEC6
      C600DEDEDE009494940000000000000000006363630094949400ADADAD00C6C6
      C600F7F7F700FFFFFF00E7E7E700CECECE00B5B5B500949494006B6B6B000000
      0000000000000000000000000000000000006363630094949400ADADAD00C6C6
      C600F7F7F700FFFFFF00E7E7E700CECECE00B5B5B500949494006B6B6B000000
      000000000000000000000000000000000000189C310021C65A0021CE63007BE7
      A500DEF7E700D6F7E700E7FFEF00FFFFFF00FFFFFF00D6F7E700D6F7E700DEF7
      E70010C6520021C65A0029C66300215200000000000000000000C6C6C600C6C6
      C600ADADAD00C6C6C600E7E7E700EFEFEF00EFEFEF00FFFFF700FFFFFF00DEDE
      DE00B5B5B500ADADAD000000000000000000525252007B7B7B0094949400ADAD
      AD00C6C6C600CECECE00C6C6C600ADADAD009C9C9C007B7B7B005A5A5A000000
      000000000000000000000000000000000000525252007B7B7B0094949400ADAD
      AD00C6C6C600CECECE00C6C6C600ADADAD009C9C9C007B7B7B005A5A5A000000
      000000000000000000000000000000000000106B080039D6730029D66B0029DE
      730029DE730029DE730084EFB500FFFFFF00FFFFFF0018DE6B0029DE730021D6
      6B0029D66B0021CE630031CE6300000000000000000000000000ADADAD00E7E7
      E700DEDEDE00D6D6D600DEDED600DEDEDE00DEDEDE00DEDED600D6D6D600E7DE
      DE00BDBDBD009C9C9C0000000000000000006363630094949400B5B5B500D6D6
      D600F7F7F700FFFFFF00F7F7F700D6D6D600B5B5B5008C8C8C00636363000000
      0000000000000000000000000000000000006363630094949400B5B5B500D6D6
      D600F7F7F700FFFFFF00F7F7F700D6D6D600B5B5B5008C8C8C00636363000000
      0000000000000000000000000000000000000000000052F7940029DE730031E7
      7B0031E77B0031EF840094F7BD00FFFFFF00FFFFFF0021E77B0031E77B0031DE
      7B0031D6730052DE840010841000000000000000000000000000CECECE00C6C6
      C600CECECE00D6CECE00D6D6D600D6D6D600D6D6D600D6D6CE00D6CECE00CECE
      CE00D6D6D6009494940000000000000000007B7B7B00ADADAD00CECECE00E7E7
      E700F7F7F700FFFFFF00F7F7F700DEDEDE00C6C6C600A5A5A500737373000000
      0000000000000000000000000000000000007B7B7B00ADADAD00CECECE00E7E7
      E700F7F7F700FFFFFF00F7F7F700DEDEDE00C6C6C600A5A5A500737373000000
      00000000000000000000000000000000000000000000107B100084F7B50031E7
      840052EF940063EF9C00A5F7C600F7FFFF00F7FFFF004AEF940039EF8C0039E7
      840042DE840042DE7B0000000000000000000000000000000000C6C6C600CEC6
      C600CEC6C600CECEC600CECECE00CECECE00CECECE00CECEC600CEC6C600CEC6
      C600C6C6C600ADADAD00000000000000000084848400B5B5B500CECECE00E7E7
      E700FFFFFF00FFFFFF00F7F7F700DEDEDE00C6C6C600ADADAD00848484000000
      00000000000000000000000000000000000084848400B5B5B500CECECE00E7E7
      E700FFFFFF00FFFFFF00F7F7F700DEDEDE00C6C6C600ADADAD00848484000000
      000000000000000000000000000000000000000000000000000010B54200ADFF
      CE0073EFAD008CF7B50094F7BD0094F7BD008CF7B5007BF7AD005AEF9C006BEF
      A50063F79C00185A000000000000000000000000000000000000A5A5A500BDBD
      B500D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6
      D600BDB5B500949494000000000000000000C6C6C600DEDEDE00EFEFEF00F7F7
      F700FFFFFF00FFFFFF00FFFFFF00F7F7F700E7E7E700D6D6D600C6C6C6000000
      000000000000000000000000000000000000C6C6C600DEDEDE00EFEFEF00F7F7
      F700FFFFFF00FFFFFF00FFFFFF00F7F7F700E7E7E700D6D6D600C6C6C6000000
      0000000000000000000000000000000000000000000000000000000000001094
      2100B5FFDE00DEFFEF00CEFFE700CEFFDE00C6F7DE00BDFFD600ADFFD60031E7
      730000000000000000000000000000000000000000000000000000000000BDBD
      BD00B5ADAD00DEDEDE00E7E7E700E7DEDE00E7DEDE00E7E7E700DED6D600B5AD
      AD00A5A5A5000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000109421004ADE84006BF7A5004AF7940021BD5200106300000000
      0000000000000000000000000000000000000000000000000000000000000000
      000094949400B5B5B500B5B5B500B5ADAD00B5ADAD00B5B5B500B5B5B5000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000600000000100010000000000000300000000000000000000
      000000000000000000000000FFFFFF00F3FFF81FFFFF0000E07FE0070FF00000
      E00FC00303C00000C003800100000000C000800100030000C000000080070000
      80000000C003000080010000D003000000010000F847000000030000F03F0000
      00030000E207000000038000CF070000800780019F070000F007C001FF070000
      FE0FE007FF070000FFDFF00FFF9F0000000180018001FF03000000000000C001
      000000000000C000000000000000C000000000000000C000000000000000C000
      000000000000C000000000000000C001000000000000C001000000000000C003
      000000000000C003000000000000C001000000000000C001000000000000C003
      000000000000C003000300030003C007F01FF00FFFFF8001C007C007C0038001
      8003C003C003800180018001C003800000010000C003800000000000C0038000
      00000000C003800000010000C003800000000000C003800000010000C0038001
      00010001C003800100008000C001800100030001C0018003C003C001C0038007
      E003E003C0038009F01FE017C007C01F0FFFF8038001C1FC00FFE003800180C0
      003FC00180018000000380008000000000010001800000000001000180000000
      0001800180000000000180018000000000010001800000000001000180018000
      0001800180018000000180018001800000018003800380008001C00780070000
      F101E00F80090001FFE1F81FC01FC3C7FFFFFFC3FFFFFFFFF81F0001E907F00F
      00000000E00FE007000000008003C003F39F000080018001F99F0000F00F8001
      F93F0000F00F0001FC3F0003E0070001FC7F0007C0030001FC7F001F80010001
      C927001FC00300018183001FFC3F8001B399001FFC3F8003B7C9001FFE7FC007
      87E3001FFE7FE00FFFFFFFFFFEFFF83FFFCFFF87F00FFFFF00070007C007800F
      0003000780030003000100008001000100010000000100010000000100000001
      0000000300008001000700070000C0030007000F0000C003001F001F0000C003
      001F001F0001C003001F001F8001C003001F001F8003C003001F001FC003C003
      001F001FE00FE007FFFFFFFFF81FF01F00000000000000000000000000000000
      000000000000}
  end
  object ImageListTree: TImageList
    Left = 112
    Top = 290
    Bitmap = {
      494C010124002700040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      000000000000360000002800000040000000A0000000010020000000000000A0
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00000000000000000000000000FEFEFE00FAFA
      FB00F2F2F600ECEBF100E7E6EE00E3E2EB00E3E2EB00E5E4EC00E9E8EF00EFEE
      F300F5F5F800FCFCFC0000000000000000000000000000000000FEFEFE00FAFA
      FA00F3F3F300ECECEC00E8E8E800E4E4E400E4E4E400E6E6E600EAEAEA00EFEF
      EF00F5F5F500FCFCFC0000000000000000000000000094949400949494009494
      940094949400949494007B7B7B007B7B7B008484840084848400949494009494
      9400949494009494940094949400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00181818005A5A5A00FFFFFF0000000000FEFEFE00EDECF200BBB7
      CE009791B400857EA7007B73A000746C9B00736B9B00776F9D007E76A2008A83
      AB00A19CBC00CDCADB00F7F7F9000000000000000000FEFEFE00EDEDED00BEBD
      BD009B9B9A008A8A890080807F007A797900797878007D7C7B00838282008F8E
      8E00A5A5A400CFCECE00F7F7F70000000000000000007B7B7B007B7B7B007B7B
      7B007B7B7B007B7B7B00FFFFFF007B7B7B008C8C8C00FFFFFF007B7B7B007B7B
      7B007B7B7B007B7B7B007B7B7B00000000001010A5002929B5004A4ACE006B6B
      DE008484E7006B6BDE000000000000000000000000000000000042C6630052CE
      73001818180052525200FFFFFF00006B080000000000FEFEFE00E3E2EB009D97
      B800716999004B3E8000281D5E002D22640031266800362B6B00524785006460
      90007C74A100B4B0C900F3F3F6000000000000000000FEFEFE00E4E4E400A1A0
      A000777776003F3F3F001E1E1E0022222200282827002C2C2C00494948006B6A
      690081818000B7B7B700F4F4F400000000000000000000000000000000000000
      0000000000000000000000000000EFD6C600B5A5940000000000000000000000
      000000000000000000000000000000000000080894002929BD005252CE007B7B
      DE00A5A5EF007B7BDE005252D600000000000000000021B542004ACE73001818
      180052525200FFFFFF00007B1000006300000000000000000000FBFBFC00B7AF
      C8000D004C000800450013005E0015006500311D790037237C0039287B003B2C
      76007B6FA800F1F1F500FDFDFD00000000000000000000000000FBFBFB00B6B3
      B1000303030003030300040404000404040021212100282828002C2C2C003030
      300071717100F2F2F200FDFDFD00000000000000000000000000000000000000
      0000E7D6CE00C6846B00D69C8C00E7BDAD00E7BDAD00DEB5A500DEBDAD00F7EF
      EF00000000000000000000000000000000008484CE002929BD003939C6006363
      D6003939CE002929BD0000009C00DEC6C600EFE7E700007B0800181818005252
      5200FFFFFF001094210018AD3900000000000000000000000000F2F0F5000E00
      5200150062009DEFFF0040C8FF00100058001F0D5400D1E2ED00CBEAF9003C27
      80003B297E007F72AC0000000000000000000000000000000000F2F1F0000505
      0500090807000A0A0A000C0B0B000B0B0B000B0B0B000B0B0B000B0B0B00302F
      2F0031303000787776000000000000000000000000000000000000000000A563
      3900E7C6B500DEAD9C00D69C8400CE948400CE948400E7C6B500DEAD9C00EFD6
      CE00C69C8C00000000000000000000000000000000001010A5005A5AD6002929
      AD0018187B004A527300845229009C5A2900C67B39001818180052525200FFFF
      FF000884180031BD5200BDDEBD00000000000000000000000000110356001501
      67001B01740028DCFF0041DCFF003FDCFF00C3D5DD0055436F000A0050001C01
      78001B01750039278000000000000000000000000000000000000B0B0A000D0C
      0B00100F0E0011100F0011100F001110100011100F0011100F0011100F001110
      0F00100F0E003231310000000000000000000000000000000000FFFFFF00DEB5
      A500D6AD9C00B5735A00AD634A00A5524200A5524200AD634A00B5735A00CE94
      8400DEAD9C0000000000000000000000000000000000FFFFFF00C6C6C6009494
      940039393900848484008C8C8C008C8C8C00525252005A5A5A00FFFFF700299C
      4200007B080000000000000000000000000000000000CBC4DA00130164001B01
      76001D017B0021057D0010005A001702650052408B001A056900270D73001D01
      7B001D017B001B0177006D5FA5000000000000000000CBC8C5000F0F0E00BFB6
      B90015CD9300191817001B1918003BD5A40043D7A800181716001A19180040D6
      A7003BD6A500161514006A6A6900000000000000000000000000AD5A3100AD63
      4200A5524200AD635200EFDED600C6948C00CEA59C00CEA58C00A55A4A008442
      3100B55A39008431000000000000000000000000000084848400BDB5B500CECE
      E700E7E7F700F7F7F700F7EFEF00EFDED600C6C6C600EFEFEF00004A0000088C
      1000088C18000000000000000000000000000000000031207A00190172002B0F
      86002B0F8600B9C4CD00240E710021CDFF00160559004BD7FF00C9D1D7002B0F
      86002B0F86001E017E00220A7A00000000000000000031302F0019171600C0BB
      BC007EE7CA00252524002B29280076E7C80081E7CB0028272500292827008CEA
      D10094EBD5001E1C1B0022201F00000000000000000000000000BD735200CE9C
      8C007B5242008C311800C6948400A55A4200AD948400E7CEC600D6B5AD008421
      0000C6847300BD7B6B000000000000000000F7F7F700D6D6CE00D6D6DE00BDBD
      DE00CECEE700DEDEE700EFDED600E7CEC600D6BDAD00B5948C006B6B6B00006B
      0000007B080000000000000000000000000000000000200E7100341C8A00371C
      9100371C910022B1FF00A99AB7003AB9FF0036B7FF006C5B940054C2FF00371C
      9100371C9100371C91001D027E00000000000000000024232200393736003C3B
      3900BEBEBD003C3B390051504F00504F4E0047464500504F4E003C3A39003A39
      38003C3B39003C3B390022201F00000000000000000000000000CEA58C00DEC6
      BD00E7D6CE00B56B5A00DEBDAD00CE9C8C00F7EFEF00F7EFE700EFDED600C69C
      8C00A58C8400AD634A0000000000000000008C8C8C00C6C6C6008C8CB500A5A5
      CE00B5B5D600D6D6E700EFEFEF00CEADA500BD9C9400DEDEDE00D6D6D6000052
      0000008C1000BDCEBD000000000000000000000000004D3C9300432C9700452C
      9C00452C9C006451A000D2DBE5007CCAFF0051B7FF00B4DCF5005CBCFF004930
      9E00452C9C00452C9C00452D9A000000000000000000535251004D4B49004F4D
      4C00A3A2A100B0B0AF00A8A8A700B0B0AF00AEAEAD00A7A6A500ACABAB00ABAB
      AA004F4D4C004F4D4C004F4D4C00000000000000000000000000DEC6B5009C7B
      7300BD8C7B00D6AD9C00E7CEC600FFF7F700FFFFFF00FFFFFF00FFF7F7009C7B
      7300BDA59C00CEA594000000000000000000E7E7E700CED6D600E7E7E700E7E7
      EF00C6C6E700C6C6E700E7CEC600DEC6BD00DEC6BD00EFEFEF0094C6A500006B
      0800FFFFFF00000000000000000000000000000000007A6BB600533DA400553D
      A8007D6BBD007D6BBD007B6AB80094D8FF0076CEFF0086D5FD00D6D9E1007D6B
      BD00553DA800553DA8006955B0000000000000000000828181005F5D5C006260
      5E008786840087868400878684007C7C7B007375730086858300878684008786
      840062605E0062605E0074727100000000000000000000000000B58473006331
      2100EFD6CE00E7C6BD00F7E7DE00EFDED600EFDED600F7EFE700F7F7F700EFEF
      EF00EFD6D600BD8C73000000000000000000E7E7E700DEDEDE00EFEFEF00EFEF
      EF00EFEFEF00EFEFEF00DEC6C600DEC6C600E7CEC600EFEFEF00F7F7F700F7F7
      F700000000000000000000000000000000000000000000000000624DAE00644D
      B4009383CB009383CB009383CB00AAE9FF008FE2FF00B7ABC9009383CB009383
      CB00644DB400644DB400D0C9DE00000000000000000000000000706E6B007472
      70009E9D9B009E9D9B009E9D9B00B8F2E300A7EEDB009B9B9A009E9D9B009E9D
      9B007472700074727000D4D1CD000000000000000000000000009C5A3100CEA5
      9C00CEC6BD00EFDED600F7E7DE00EFDED600CEC6C600D6CEC600F7EFEF00FFFF
      FF00EFE7DE00CEAD9C000000000000000000FFFFFF00FFFFFF00F7F7F700F7F7
      F700F7F7F700F7F7F700E7DED600E7DED600E7DED600E7DEDE00BDBDBD00FFFF
      FF000000000000000000000000000000000000000000000000008D7EC600735D
      BD00A89BD600A89BD600A89BD600A89BD600A4F1FF00A79BD400A89BD600A89B
      D600735DBE007C68C20000000000000000000000000000000000999796008381
      7F00B2B1B000B2B1B000B2B1B000FBFFFF00FAFFFF00B1B0B000B2B1B000B2B1
      B000848280008B8988000000000000000000000000000000000000000000EFDE
      D600FFF7F700E7DEDE00DEDED600FFF7F700FFF7F700F7EFE700F7EFEF00FFFF
      FF00BD8C730000000000000000000000000000000000DEDEDE00FFFFFF00F7F7
      F700FFFFFF00FFFFFF00FFF7EF00F7F7EF00F7F7F700ADB5AD00E7E7E7000000
      0000000000000000000000000000000000000000000000000000000000008876
      C800B7ACDF00B9AEE100B9AEE100B9AEE100FEFFFF00B9AEE100B9AEE100B9AE
      E100836FC8000000000000000000000000000000000000000000000000009795
      9400C1C0BE00C4C2C000C4C2C000C4C2C000C4C2C000C4C2C000C4C2C000C4C2
      C000949290000000000000000000000000000000000000000000000000000000
      000094421800F7EFEF00F7EFEF00F7EFEF00FFF7F700F7EFEF00FFF7EF008C39
      0800000000000000000000000000000000000000000000000000D6D6D600D6DE
      DE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00A5A5A500E7E7E700000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000AA9CDB00C8BFE800C7BEE800C7BEE800C7BEE800C7BEE800C7BEE800A08F
      D700000000000000000000000000000000000000000000000000000000000000
      0000B6B5B400D1D0D000CFCECE00CFCECE00CFCECE00CFCECE00CFCECE00AEAC
      AC00000000000000000000000000000000000000000000000000000000000000
      000000000000EFE7DE0084290000B5735200AD6B4A0084310000FFFFFF000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF009C9C9C00A5A5A5009C9C9C00EFEFEF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000B8ABDF00B0A2DF00AFA1DF00AC9DDC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000C3C1BF00BDBBBA00BCBBBA00B9B7B500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00393984000000940008089C000808
      6300D6D6D6000000000000000000000000000000000000000000000000000000
      000000000000CECECE00CEAD7300CEA57300CEA57300B59C7B00DEDEDE000000
      00000000000000000000000000000000000000000000E7E7E700F7F7F700FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F7F7F700EFEFEF00A5A5A500FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF0084CEE700E7CEBD00FFD6AD00F7F7F700FFFFFF00000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00EFE7DE00E7D6C6007B6B8C00525AFF000000E7000000EF002129F7000000
      E7000810EF0000006B000000000000000000000000000000000000000000E7E7
      E700D6AD7B00D6AD7B00D6AD7300CEAD7300CEA57300CEA57300CEA56B00CEA5
      6B00F7F7F70000000000000000000000000000000000E7E7E700F7F7F700FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F7F7F700EFEFEF00BDBDBD00A5A5
      A500FFFFFF00000000000000000000000000000000000000000000000000FFFF
      FF0084736B00947B3100FFFFFF00FFFFFF00FFDEB500D6D6D600F7F7F700FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000F7EFEF00CEB5
      A500CEA594009C7B84000000E7000810BD003939C60018108C00312973000000
      AD000810BD000008CE0000006300000000000000000000000000DEDEDE00D6AD
      7B00D6AD7B00D6AD7B00D6AD7B00E7E7E700CEAD7300CEAD7300CEA57300CEA5
      7300CEA56B00F7F7F700000000000000000000000000E7E7E700F7F7F700FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00EFEFEF00BDBDBD00EFEF
      EF00A5A5A500FFFFFF0000000000000000000000000000000000000000000000
      0000E7BD9C00FFC68400FFF7E700FFFFFF00FFFFFF00DEDEDE00D6D6D600DEDE
      DE00FFFFFF0000000000FFFFFF000000000000000000FFFFFF00D6BDB500BD94
      8400FFCE9C003942BD0000009C000008B5000000B500D6AD9400F7CEA500C694
      7B00AD8C8C000000A5000008BD00DEDEE70000000000FFFFFF00D6B58400D6B5
      8400D6AD8400D6AD7B00D6BD9400EFEFEF00EFE7E700D6AD7300CEAD7300CEAD
      7300CEA57300CEA57300000000000000000000000000E7E7E700F7F7F700FFFF
      FF00FFFFFF00CECECE00E7E7E700FFFFFF00FFFFFF00F7F7F700BDBDBD00B5B5
      B500BDBDBD00A5A5A500FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00E7E7E700ADADAD00F7F7F700D6D6
      D600CECECE00FFFFFF00000000000000000000000000FFFFFF00DEC6BD00EFAD
      6B00D68C52000000A50010108400212973000808A5000000AD00BDA59C00DEA5
      7300F7BD840000084A0000006B0008085A0000000000D6B58C00D6B58400D6B5
      8400D6B58400E7DECE00EFEFEF00EFEFEF00EFEFEF00EFEFE700D6AD7B00D6AD
      7300CEAD7300CEAD7300DEDEDE000000000000000000E7E7E700F7F7F700EFEF
      EF00DEDEDE00D6D6D600B5B5B500FFFFFF00BDBDBD00BDBDBD00C6C6C600EFEF
      EF00CECECE00EFEFEF00F7F7F700000000000000000000000000FFFFFF00FFFF
      FF00F7F7F700D6D6D600B5B5B500ADADAD00A5A5A500A5A5A500A5A5A500DEDE
      DE00D6D6D600F7F7F70000000000000000000000000000000000EFA56B00C67B
      39007B4A5200000063001818A500BDA59400181894000008B5000000B5009C5A
      3100CE8C5A00D6BDA50000005A0029318C0000000000DEB58C00D6B58C00D6B5
      8C00D6B58400F7F7F700F7F7F700F7F7EF00D6AD7B00EFEFEF00D6B58C00D6AD
      7B00D6AD7300D6AD7300B59C7B000000000000000000E7E7E700E7E7E700CECE
      CE00CECECE00CECECE00D6D6D600CECECE00CECECE00BDBDBD00E7E7E700DEDE
      DE00E7E7E700F7F7F700F7F7F70000000000000000000000000000000000FFFF
      FF00E7E7E700B5847300C6A59400CEA59C00C6A59400BD948C00944A3100FFFF
      FF00FFFFFF000000000000000000000000000000000000000000BD6B2900C673
      3100945A520000008C001010AD00FFFFFF00FFFFFF000810BD000008BD000000
      B500A5633900B57B630000008C001821A50000000000DEBD9400DEBD9400D6B5
      8C00D6B58C00D6B58C00D6B58400F7F7F700D6B58C00F7EFEF00D6AD7B00D6AD
      7B00D6AD7B00D6AD7B00D6AD73000000000000000000E7E7E700DEDEDE00CECE
      CE00C6C6C600CECECE00CECECE00EFEFEF00BDBDBD00E7E7E700F7F7F700F7F7
      F700F7F7F700FFFFFF00F7F7F700000000000000000000000000000000000000
      00009C5A4200C68C8400734A3900845A4A008C5A4A00945A4A009C5A42007B29
      0800FFFFFF0000000000000000000000000000000000EFA56300BD632100C673
      3900D68C52001818C6002929AD00F7F7F700E7E7E700FFFFFF000808E7001821
      C6001018BD0031395A001818A5000000840000000000DEBD9C00DEBD9400DEBD
      9400DEBD9400D6B58C00FFF7F700F7F7F700F7F7F700F7F7F700D6B58400D6AD
      8400D6AD7B00D6AD7B00D6AD7B000000000000000000E7E7E700E7E7E700C6C6
      C600CECECE00EFEFEF009C9C9C00C6C6C600C6C6C600C6C6C600E7E7E700BDBD
      BD00DEDEDE00FFFFFF00F7F7F700000000000000000000000000000000008431
      10007B290800E7E7E700EFEFEF00F7F7F700FFFFFF00F7F7F700DEDEDE00FFFF
      FF00F7F7F70000000000000000000000000000000000CE733100DEB59400CE84
      4A00C6C6BD005A63CE00424ACE003131AD0021212100C6C6C600EFEFEF000000
      E7004A4AD600424AD6005252E7000000000000000000DEBD9C00DEBD9C00DEBD
      9400DEBD9400F7F7EF00FFFFFF00FFFFFF00D6B58C00D6B58400D6B58400D6B5
      8400D6AD8400D6AD7B00D6AD7B000000000000000000E7E7E700E7E7E700CECE
      CE009C9C9C00F7F7F700EFEFEF00CECECE00D6D6D600C6C6C600CECECE00FFFF
      FF00FFFFFF00FFFFFF00F7F7F700000000000000000000000000000000008431
      10007B290800DEDEDE00E7CEC600944A3100AD735A00A5634A00CEA59C008C42
      21007B29080000000000000000000000000000000000BD5A1800BD6B3100F7E7
      D600CEBDB500EFEFEF008484F7006B73EF008C8CDE0010187B0008087300424A
      8C006B73EF006B73F7000810A5000000000000000000DEC6A500DEC69C00DEBD
      9C00DEBD9C00FFFFFF00FFFFFF00FFFFFF00DEB58C00D6B58C00D6B58C00D6B5
      8400D6B58400D6B58400CECECE000000000000000000E7E7E700EFEFE700C6C6
      C600DEDEDE00C6C6C600DEDEDE00D6D6D600DEDEDE00D6D6D600FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F7F7F700000000000000000000000000DECEC6007B29
      08007B290800C6C6C600EFD6D6009C634A008C422100A5635200D6B5AD00CE94
      8C007B29080000000000000000000000000000000000C66B2100B55A1800C673
      3900C6733900FFFFFF00FFFFFF009CA5F7009CA5FF009CA5FF009CA5FF009CA5
      FF00ADADFF0029218C00FFEFDE000000000000000000F7F7F700DEC6A500DEC6
      A500DEC69C00DEBD9C00FFFFFF00FFFFFF00FFFFFF00FFFFFF00D6B58C00D6B5
      8C00D6B58C00D6B58400000000000000000000000000E7E7E700EFEFEF00EFEF
      EF009C9C9C00DEDEDE00DEDEDE00EFEFEF00E7E7E700E7E7E700FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F7F7F700000000000000000000000000000000007B29
      0800A56B5200E7D6CE006B6B6B00A56B5200A56B5200EFDEDE00E7CEC600CE9C
      8C007B29080000000000000000000000000000000000FFFFFF00B5521000C673
      3900CE8C5A00D6A57B00FFFFFF00C6C6C600CECECE001818BD000008C6008C5A
      6300CE946B00AD52100000000000000000000000000000000000E7C6AD00E7C6
      A500DEC6A500DEC6A500DEC69C00FFFFFF00FFF7EF00DEBD9400DEBD9400DEBD
      8C00D6B58C00E7E7E700000000000000000000000000E7E7E700EFEFEF00F7F7
      F700F7F7F700F7F7F700F7F7F700D6D6D600F7F7F700E7E7E700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F70000000000000000000000000000000000BD84
      7B00BD948400BD948400BD948400BD948400BD948400EFE7DE00EFD6D600E7C6
      C600BD9484000000000000000000000000000000000000000000AD4A0000C673
      3900D6946B00D6A57B00DEA58400DEAD8C00DEAD8400DEA58400D6A57B00CE94
      6B00E7CEB500AD5218000000000000000000000000000000000000000000E7CE
      AD00E7C6AD00DEC6A500DEC6A500DEC6A500DEBD9C00DEBD9C00DEBD9400DEBD
      9400DEDEDE0000000000000000000000000000000000E7E7E700EFEFEF00EFEF
      EF00E7E7E700FFFFFF009C9C9C00F7F7F700EFEFEF00F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700000000000000000000000000000000007B29
      0800F7E7E700EFDEDE00D6B5AD00D6B5AD00D6B5AD00F7E7E700E7CECE00EFD6
      D60000000000000000000000000000000000000000000000000000000000B55A
      1800D69C7300EFD6BD00E7BDA500E7C6A500E7BDA500E7BDA500DEB59400CE94
      6300AD4A0000FFFFFF0000000000000000000000000000000000000000000000
      0000F7F7F700E7C6AD00E7C6A500DEC6A500DEC6A500DEC69C00DEBD9C00FFFF
      FF000000000000000000000000000000000000000000E7E7E700E7E7E700EFEF
      E700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00F7F7EF00F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700000000000000000000000000000000000000
      0000944A3100F7EFE700F7EFEF00EFDEDE00EFDEDE00F7EFEF00F7E7E7000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000BD6B3100DEAD8C00E7CEB500EFD6BD00EFD6BD00E7C6AD00D6A58400B552
      1800000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700FFFFFF00000000000000000000000000000000000000
      0000000000000000000084391800FFFFFF00DECEC600BD948400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000E7C6AD00BD734200CE946B00CE946B00BD6B3100000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000BDBDBD00BDBD
      BD00BDBDBD00BDBDBD00C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600CECE
      CE00DEDEDE000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F7F7F700E7E7E700D6D6D600BDBDBD00B5B5B500D6D6D600E7E7E700F7F7
      F700000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00087B3900F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7EFEF00EFEF
      EF00FFFFFF00EFEFEF0000000000000000000000000000000000FFFFFF00FFFF
      FF00F7F7F700E7E7EF005A4ACE006B5AD6007363D6005242CE00F7F7F700FFFF
      FF00FFFFFF00FFFFFF000000000000000000000000000000000000000000FFFF
      FF009C9C94005A63520084CE63005AC642004ACE39007BBD5A00525A4A00848C
      7B00FFFFFF0000000000000000000000000000000000E7E7E700E7E7E700E7E7
      E700DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDED600D6D6D600DEDED600D6D6
      D600E7E7E700FFFFFF00FFFFFF00000000000000000000000000F7F7F70031CE
      7B0008C65A0031CE7B00F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F7009C9C9C00FFFFFF0000000000000000000000000000000000000000000000
      00005A4AD6004A39BD00D6D6DE00DEDEE700DEDEDE00DEDEDE00CEC6FF006352
      D60000000000000000000000000000000000000000000000000000000000F7F7
      F700B5CE9C009CC67B006BD64A0031E7390031E7390052CE420094BD7300C6D6
      B500F7F7F70000000000000000000000000000000000FFFFFF00EFEFEF00EFEF
      EF00EFE7E700EFE7E700E7E7E700E7DEDE00E7DEDE00DEDED600E7E7DE00E7E7
      E700F7F7F700FFFFFF00ADADAD00000000000000000000000000F7F7F700F7F7
      F700F7F7F70010AD520010AD5A00F7F7F700F7F7F700F7F7F700F7F7F7007B7B
      7B005A5A5A00EFEFEF0000000000000000000000000000000000000000004239
      C600E7E7E700BDC6C6007BA5D6009CF7FF00A5F7FF005A6BB500BDC6CE00D6D6
      D6009C94DE00000000000000000000000000000000000000000000000000FFFF
      FF00BDCEAD00ADD68C0063E7520031FF5A0031FF63004ADE42009CC67B00CEDE
      C600FFFFFF0000000000000000000000000000000000FFFFFF00FFE7D600FFDE
      D600F7F7F700F7F7F700F7EFEF00EFEFEF00EFEFEF00EFE7E700E7E7E700E7E7
      DE00E7E7E700F7F7F700FFFFFF00000000000000000000000000F7F7F700F7F7
      F700F7F7F700F7F7F70018C66300F7F7F700F7F7F700F7F7F700525252005A5A
      5A00F7F7F700F7F7F700000000000000000000000000000000004239CE00DEDE
      DE0031318C007BE7FF0073E7FF005ADEF7005ADEF7007BE7FF008CEFFF006B7B
      9400D6D6D6006352D60000000000000000000000000000000000000000000000
      0000BDCEAD00B5D694005AEF4A0039FF520031FF5A0042E74200A5CE8400D6DE
      C6000000000000000000000000000000000000000000FFFFFF00FFE7D600FFDE
      D600FFFFFF00F7F7F700F7F7F700EFEFEF00EFEFEF00EFEFE700E7E7E700E7E7
      E700E7E7DE00E7E7E700F7F7F700000000000000000000000000F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F70008D66300F7F7F7003131310042424200F7F7
      F700F7F7F700F7F7F700000000000000000000000000A5A5E700635AC600B5BD
      BD0073E7F7004ACEF7004AC6F7004AC6EF004AC6EF004AC6EF004ACEF7007BE7
      F700BDBDC600A59CE700FFFFFF00000000000000000000000000000000000000
      0000BDC6AD00B5DE9C004AF74A0031F74A0031FF4A0042E742009CD68400CED6
      C6000000000000000000000000000000000000000000FFFFFF00FFE7DE00FFE7
      D600FFFFFF00FFFFFF00F7F7F700F7F7F700F7EFEF00EFEFEF00EFEFEF00EFE7
      E700E7E7E700E7E7DE00E7E7E700000000000000000000000000F7F7F700F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F7003131310052525200F7F7F700F7F7
      F700F7F7F700F7F7F7000000000000000000000000006B63DE00E7E7E7002118
      840039ADEF0042BDEF0052CEFF0039ADEF0039ADEF0039ADEF0063CEF7002118
      9C0018106B00CECECE004231D600000000000000000000000000000000000000
      0000ADBDA500ADEF9C004AFF6300000000000000000031F7390094DE7B00C6CE
      BD000000000000000000000000000000000000000000FFFFFF00FFE7DE00F7E7
      D600FFFFFF00FFFFFF00FFFFFF00F7F7F700B5C6F700B5C6EF00A5D6A500EFEF
      EF0052CE5A00E7E7E700E7E7DE00000000000000000000000000F7F7F700847B
      7B00DED6D600DED6D600948C8C009C9C9C006B6B6B00F7F7F700F7F7F700F7F7
      F700F7F7F700F7F7F700000000000000000000000000948CEF00E7E7E7002118
      9C003129E7003129D6002984E7002984E7002984E7002984E700319CEF002118
      9C0018107300CECED6005A52DE00000000000000000000000000000000000000
      0000A5AD9C00C6FFBD00A5FFBD00000000000000000029FF630084EF8400BDC6
      B5000000000000000000000000000000000000000000FFFFFF00FFE7DE00FFE7
      D600FFFFFF00EFF7EF00FFFFFF005ABD6300B5CEF7006BAD6B00F7EFEF004AA5
      5200EFEFEF00007B1000E7E7E700000000000000000000000000C6BDBD00EFE7
      E700E7E7E700E7E7E700E7DEDE00E7DEDE00EFEFEF00EFEFEF00F7F7F700F7F7
      F700F7F7F700F7F7F700000000000000000000000000C6BDF700E7E7EF002118
      9C003121BD00639CF700215ADE00215ADE00427BF7003121C6002929EF002921
      AD0018107300CECED6005242DE00000000000000000000000000000000000000
      0000949C8C00D6DECE00CEDEBD0052D64A0042EF520073B55200C6D6BD00ADB5
      A5000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F7F7F700F7F7F700F7EF
      EF00EFEFEF00EFEFEF00EFE7E700000000000000000063636300F7EFEF00EFE7
      E700EFE7E700F7EFEF00F7EFEF00F7EFEF0063636300EFEFEF00EFEFEF00F7F7
      F700F7F7F700F7F7F700000000000000000000000000DEDEF700FFFFFF002118
      94003121B5005A7BF7005242DE00426BEF001839DE004A4AEF004A42CE003931
      AD0018107300D6D6D6004231D600000000000000000000000000000000000000
      00008C8C8C00F7F7F700F7F7F700E7E7E700E7E7E700E7E7E700E7E7E700ADAD
      AD000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F7FFF700F7F7F700F7F7
      F700EFEFEF00EFEFEF00EFEFE70000000000000000005A5A5A00EFEFEF00F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F70084848400EFEFEF00EFEFEF00F7F7
      F700F7F7F700F7F7F7000000000000000000000000006B6BD600948CD6009494
      A500635AC600736BD600736BDE004A6BEF000818D6007BA5FF00736BCE007B73
      D600B5B5BD004231C600D6D6F700000000000000000000000000000000000000
      00008C8C8C00F7F7F700F7F7F700D6D6D600D6D6D600D6D6D600E7E7E700ADAD
      AD000000000000000000000000000000000000000000D6D6D600D6D6D600D6D6
      D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600D6D6D600CECECE00CECE
      CE00CECECE00CECEC600C6C6C600000000000000000094949400F7F7F700FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0094949400EFEFEF00EFEFEF00EFEF
      EF00F7F7F700F7F7F70000000000000000000000000000000000F7F7FF00FFFF
      FF0021108C00A59CDE00A5ADF7001821DE00A5A5E700A59CDE009C9CD6002121
      7300DEDEDE004231CE0000000000000000000000000000000000000000000000
      0000ADADAD00EFEFEF00F7F7F700DEDEDE00DEDEDE00E7E7E700D6D6D600BDBD
      BD000000000000000000000000000000000000000000006BFF000073FF00007B
      FF00007BFF000084FF00008CFF000094FF000094FF00009CFF0000A5FF0000A5
      FF0000ADFF0000B5FF0000BDFF00000000000000000000000000F7F7F700FFFF
      FF00FFFFFF00FFFFFF00F7F7F700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEF
      EF00F7F7F700F7F7F70000000000000000000000000000000000FFFFFF00736B
      D600FFFFFF009C94AD00C6C6E700CEDEFF00CECEEF00BDB5DE00ADADAD00EFEF
      EF004231C6000000000000000000000000000000000000000000000000000000
      0000C6C6C600FFFFFF00F7F7F700F7F7F700F7F7F700F7F7F700FFFFFF00C6C6
      C6000000000000000000000000000000000000000000006BFF000073FF000073
      FF00007BFF000084FF000084FF00008CFF000094FF00009CFF00009CFF0000A5
      FF0000ADFF0000ADFF0000B5FF00000000000000000000000000F7F7F7007B7B
      7B00FFFFFF00FFFFFF00A5A5A500EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEF
      EF00F7F7F700F7F7F7000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00948CDE00FFFFFF00EFEFEF00E7E7E700F7F7F7005A52C6004231
      BD00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000F7F7F700F7F7
      F700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00F7F7
      F700F7F7F700F7F7F70000000000000000000000000000000000000000000000
      0000000000006363CE00D6D6EF009C94DE00635AC6004A39BD008484DE000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000D6D6D600D6D6
      D600D6D6D600DEDEDE00DEDEDE00DEDEDE00DEDEDE00D6D6D600D6D6D600D6D6
      D600D6D6D600D6D6D60000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF009494DE005252C6003139
      BD002931B500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFF7F700EFE7DE00EFDED600EFDED600F7EFE700FFFF
      FF0000000000000000000000000000000000636BCE002929C6002129CE002121
      D6001818DE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEDEDE003939420052525200E7E7
      E700000000000000000000000000000000000000000000000000000000000000
      0000DEDEDE00391018005A5A5A00F7F7F7000000000000000000000000000000
      0000F7F7F700E7E7E700D6D6D600BDBDC600B5B5B500D6D6D600E7E7E700F7F7
      F70000000000000000000000000000000000BDBDBD0084848400000000000000
      0000F7EFEF00E7CEBD00DEAD9C00EFAD8400FFCEA500FFC69400E79C7300DEC6
      B500EFDED600FFFFFF000000000000000000FFFFFF002129E7002121E7002139
      E700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00D6D6CE006B6B6B00EFEFE7001818
      180039393900EFEFEF0000000000000000000000000000000000BDBDBD002121
      210052000800C6001000FF001000EFEFEF00000000000000000000000000FFFF
      FF009C9CA5005A6B730094DEFF007BC6DE007BC6DE007BBDDE00525A6300848C
      9400FFFFFF000000000000000000000000006363630021212100847B7B00F7EF
      E700E7CEBD00FFA56300FFCEAD00FFDEC600FFE7D600FFE7D600FFD6B500FFC6
      9400DE8C4A00EFD6CE00FFFFFF0000000000FFFFFF002121E7002142E7002142
      E700FFFFFF00FFFFFF00FFFFFF00FFFFFF009C731800946B0000946B00009C73
      1800FFFFFF00FFFFFF00FFFFFF00FFFFFF00C6C6C600F7F7F700ADADAD00D6D6
      D60021212100212121005A5A5A00F7F7F7009C9C9C0021212100212929005200
      0000C6081800FF081800FF001000FFFFFF00000000000000000000000000F7F7
      F70094C6E70094CEFF0084E7FF0084D6E70084D6EF006BC6E70084B5DE00B5D6
      E700F7F7F700000000000000000000000000000000004242420021212100846B
      6300FFA56300FFBD8C00FFCEAD00FFDEC600FFE7D600FFE7D600FFDEC600FFCE
      AD00FFBD8400D67B3100F7E7DE00FFFFFF00525AEF003142EF003152EF00FFFF
      FF00FFFFFF00FFFFFF00EFE7CE00946B0000B58C2100E7B53900EFBD4200D6AD
      39009C731000FFFFF700FFFFFF00FFFFFF00F7F7F700A5A5A500E7DEDE00D6D6
      D600A5A5A500636363003939390031313100313131004239390052000000B500
      1000FF102900E72129000000000000000000000000000000000000000000FFFF
      FF00A5CEE700A5DEFF008CF7FF008CDEEF00CEEFF70073CEEF008CC6EF00C6DE
      EF00FFFFFF0000000000000000000000000000000000000000004A4A4A002929
      29008C5A3900FFA56300FFC69C00FFCEAD00FFD6BD00F7D6B500F7CEA500FFC6
      9400FFAD6B00FF9C5200D69C7300FFFFFF001818E7005A63B500FFFFFF00FFFF
      FF00FFFFFF00FFFFFF009C730800F7C62100EFBD2100FFEFBD00FFF7DE00F7D6
      6B00EFB50000C69C3100FFFFFF00FFFFFF0000000000FFFFFF00B5B5B500CECE
      CE00D6D6D6006B7373008C8C8C00BDB5BD005A3131007B081000C6000800F718
      2900C6737B000000000000000000000000000000000000000000000000000000
      0000ADCEE700ADDEFF0084F7FF0084DEEF008CDEF70084DEF7008CC6EF00CEDE
      E700000000000000000000000000000000000000000000000000EFD6CE008484
      840063636300D6B59C00DED6CE00E7D6CE00CEBDB5008C847B00FFD6B500EFBD
      9400FFB57B00E7842900D66B1800FFFFFF001818E70021299400FFFFFF00FFFF
      FF00FFFFFF00CEBD8C00EFBD1000F7F7E700FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00EFBD1800FFFFFF00FFFFFF000000000000000000FFFFFF00CECE
      CE00D6D6D600E7E7DE00525252009C9C9C00B5292900EF001800F70818007B6B
      730084848400A5A5A50000000000000000000000000000000000000000000000
      0000ADCEDE00B5E7FF0084EFFF0084DEF700183139006BCEEF0094C6EF00C6D6
      E700000000000000000000000000000000000000000000000000CE7B3900D66B
      1800D6D6CE00FFE7BD00FFE7D600FFE7D600FFEFE700FFF7EF00847B7B00FFDE
      BD00FFCEAD00E77B2900CE631000FFF7F7004252EF00425ACE0029319C00FFFF
      FF00FFFFFF00CEA52900EFC64A002173420031845200FFFFFF00FFFFFF00FFFF
      FF00CEB56B00D6AD2100DEA50800CEA510000000000000000000FFFFFF000000
      0000D6D6D600E7E7DE00CECECE0084000800FF5A6B00FF081000949C9C009C9C
      9C00D6D6D600ADADAD0000000000000000000000000000000000000000000000
      0000A5BDCE00BDEFFF007BEFFF00183139001831390073DEF70094CEEF00BDCE
      DE00000000000000000000000000000000000000000000000000C65A0800DE7B
      2100F7D6A500FFEFDE00FFF7EF00FFEFDE00FFEFE700FFF7EF00FFF7F700F7E7
      D600F7DEC600F79C5A00CE631000EFCEB500FFFFFF002139E70018218C000810
      8C007B7BBD00B594310042429C0018DEC60039946B00297B4A00FFFFFF00FFFF
      FF00FFFFFF00EFBD1000E79C0000DE9C00000000000000000000000000000000
      000000000000BDC6C60052525200CED6D6007363630000000000FFFFFF00F7F7
      F700FFFFFF000000000000000000000000000000000000000000000000000000
      000094ADBD00C6F7FF0084FFFF001831390073EFF70063CEF7009CCEF700ADC6
      CE00000000000000000000000000000000000000000000000000CE631000F79C
      5A00F7BD5A00FFE7CE00FFEFE700FFE7D600FFEFDE00FFF7E700FFF7F700CEC6
      BD00F7BD9400EF944A00CE631000EFD6C600FFFFFF00FFFFFF001839E700425A
      C60018218C0018218C0018218C00B5ADEF0010CEB50063C6B500FFFFFF00FFFF
      FF00FFFFFF00EFBD1000E79C0000FFFFFF000000000000000000000000000000
      0000FFFFFF008C948C00C6C6C600C6CEC600FFFFFF007B7B7B00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000738C9C00CEFFFF00ADFFFF0094BDBD00BDEFF7006BDEF7009CDEF7009CB5
      BD00000000000000000000000000000000000000000000000000D69C6B00FFAD
      6B00FFEFE700FFE7DE00FFFFF700FFE7D600FFE7D600FFEFE700FFF7EF00EFCE
      BD00FFBD8400F79C5200DE732100FFFFFF00FFFFFF00FFFFFF00FFFFFF00BDC6
      F7001831E7000831E7004A63EF00FFFFFF00FFFFFF0010CEB500FFFFFF00FFFF
      FF00FFFFFF00E7AD1000FFFFFF00FFFFFF00000000000000000000000000DEDE
      DE00CECEC600FFFFFF0000000000DEDEDE00BDBDBD00FFFFFF00525A6300636B
      6B00DEDEDE000000000000000000000000000000000000000000000000000000
      000073848C00D6EFFF00C6E7F7007BD6EF0094DEEF0073C6E700CEE7F7009CAD
      AD00000000000000000000000000000000000000000000000000FFFFF700FFB5
      7B00D6CECE00FFF7E700FFEFE700FFF7EF00FFF7E700FFF7E700CEC6BD00EFB5
      8C00FFAD6B00FFA56300D66B180000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF004AD6C600FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000008C8C8C00BDC6
      C60000000000000000000000000000000000E7E7E700636B6B0021292900FFFF
      F700737373000000000000000000000000000000000000000000000000000000
      00008C8C8C00F7F7F700F7F7F700D6D6D600D6D6D600DEDEDE00E7E7E700ADAD
      AD0000000000000000000000000000000000000000000000000000000000DEA5
      6300FFF7EF00CEC6C600FFFFF700F7F7F700F7EFEF00C6BDB500FFCEAD00FFB5
      7B00FFCE9C00FFA56300EFE7DE0000000000FFFFFF00FFFFFF00FFFFFF00DEEF
      E7008CC6A50039946300FFFFFF00EFF7EF00297B4A0031DEC600FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000D6D6D600C6C6CE000000
      0000000000000000000000000000000000007B7B7B006B6B6B00D6D6D600CECE
      CE00B5B5B5000000000000000000000000000000000000000000000000000000
      0000ADADAD00EFEFEF00F7F7F700DEDEDE00DEDEDE00E7E7E700D6D6D600BDBD
      BD00000000000000000000000000000000000000000000000000000000000000
      0000EF9C5A00FFEFDE00F7E7DE00E7E7DE00F7EFEF00FFCEA500FFC69400FFC6
      9C00FFDEBD00D6C69C000000000000000000FFFFFF00FFFFFF00FFFFFF003194
      5A00318C5200318C4A0021734200297B4A005AB594004ADEC600FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000C6C6C600FFFFFF0084848400CECE
      CE00FFFFFF000000000000000000000000000000000000000000000000000000
      0000C6C6C600FFFFFF00F7F7F700F7F7F700F7F7F700F7F7F700FFFFFF00C6C6
      C600000000000000000000000000000000000000000000000000000000000000
      000000000000D6B58C00FFE7CE00FFDEBD00FFD6B500FFD6B500FFD6B500F7B5
      7B00F7F7E700000000000000000000000000FFFFFF00FFFFFF00FFFFFF0021C6
      A50031CEAD0029CEA50029AD840018CEAD00BDEFE700FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF008484
      8400E7E7E7000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F7EFEF00DECEB500E7D6C600FFFFFF000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00E7F7F70084DEC600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFF7F700FFF7F700FFF7F700FFFFFF00F7F7EF00C6D6
      BD00C6D6BD00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      F700EFDED600E7C6BD00DEB5A500D6AD9400DEAD9400DEBDB5009CA57B000094
      210000941800FFFFFF0000000000000000000000000000000000000000000000
      00000000000073A59400EFF7F700000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      000000000000F7F7F700C6C6C600ADADB500B5B5B500E7E7E700000000000000
      0000000000000000000000000000000000000000000000000000F7EFEF00E7D6
      CE00E79C6B00FFCE9C00FFDEBD00FFE7CE00FFDEC600FFD6AD00AD94420000A5
      290000A52900FFFFFF00FFFFFF0000000000000000000000000000000000FFFF
      FF0063948400107B52009CB5AD00F7F7F700FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000F7F7
      FF00D6E7EF00EFF7F7000000000000000000000000000000000000000000DEDE
      DE0018188C000000A5000000A50000009C0000009C000000A500000094009494
      A5000000000000000000000000000000000000000000FFF7EF00EFDED600F79C
      4A00FFCEA500FFD6B500FFE7CE00FFEFDE00089C290010A5310010AD390000B5
      390000B53900089C29001094290063AD63000000000000000000FFFFFF00528C
      7300188C5A00108C5A006B8C8400DEDEDE00EFEFEF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000F7F7FF00B5D6
      DE003194FF00ADCEDE00F7FFFF0000000000000000000000000084849C000000
      A5000000A500315AD600638CEF007B9CF700739CF7005273DE000818B5000000
      9C0021218C00000000000000000000000000FFFFFF00F7EFEF00E7842900FFB5
      7B00FFB57B00FFCEA500FFDEBD00FFE7CE00E7D6B50000D6520000CE4A0000C6
      4A0000BD420000B5390010B542000000000000000000000000004A847300219C
      6B00189C6300219C6B0018634A00CECECE00DEDEDE00EFEFEF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00CEDEEF00319C
      FF00319CFF002994FF00E7EFF7000000000000000000ADADB50000009C001052
      E7002973F700005AEF000052EF00004AEF00004AE700004AE7002963E7004273
      EF000000A50029218C000000000000000000FFFFFF00D69C7B00FF944200FF94
      3900FFBD8C00FFC69C00FFD6AD00FFDEBD00FFD6BD00ADB5730042EF8C0042E7
      840042DE84005AE79400F7F7EF0000000000000000008CB5AD0021AD6B0021A5
      6B0021A56B0039AD7B00005A3900CECECE00CECECE00DEDEDE00EFEFEF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000DEEFF70063B5
      FF00319CFF00319CFF007BB5D600FFFFFF00000000000000A5000863F700085A
      F700005AF7000052F700005AF7000052EF000052EF000052EF00004AEF00004A
      E700105AEF000008A500CECECE000000000000000000D66B1800E77B2900EF84
      3100FFC69C00FFBD8C00FFC69C00FFCEA500FFD6B500FFD6BD008CC684007BF7
      AD0073F7AD00AD732100D6A57B00000000000000000073A5940031B57B0031AD
      7B0031AD7B0029AD730084BDA50031735A00CECECE00DEDEDE00EFEFEF00F7F7
      F7006B948C000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF007BB5
      DE00319CFF00319CFF003194F700F7FFFF00C6C6CE00104ADE00186BF700005A
      F700C6DEFF00FFFFFF00005AF700005AF7000052F700C6D6FF00FFFFFF00316B
      EF000052EF000052EF00292994000000000000000000D6631000D66B1800E773
      2100FFE7CE00FFCEAD00FFDEC600FFEFDE00FFF7E700FFEFE700FFE7D600ADEF
      C6009CB56B00CE631000C66318000000000000000000B5CEC60052C6940052BD
      8C0052BD8C004ABD8C0073CEA500318C6B008CA59C00F7F7F700B5C6BD000063
      4200187352000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000DEEF
      F70039ADFF0031A5FF00319CFF00F7FFFF007373A500297BFF00216BF7004A8C
      F700FFFFFF00FFFFFF00FFFFFF002973F700E7EFFF00FFFFFF00FFFFFF00ADC6
      FF000052EF000052EF000018B50000000000EFEFEF00DE731800EF944A00F794
      4A00FFEFE700FFDEC600FFD6B500FFDEBD00FFE7D600FFF7EF00FFF7EF00FFE7
      CE00FFCE9C00CE631000CE63080000000000000000000000000052B58C006BCE
      9C006BCE9C006BCE9C0063C69C00A5E7C60018845A00217B5A0010845A0021AD
      6B004A9C7B00000000000000000000000000FFFFFF00E7F7F700E7EFF700E7EF
      F700E7EFF700E7EFF700EFF7F700FFFFFF00000000000000000000000000DEEF
      F70031ADFF0031ADFF0039A5FF00FFFFFF00737BAD00297BF7002973F7002173
      F7004A84F700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0084ADF7001063
      F700005AF700005AF7000042E70000000000F7F7F700F79C4A00FF943900F7B5
      8400FFD6AD00FFD6B500FFD6AD00FFDEBD00FFE7D600FFEFE700FFEFDE00FFD6
      B500FFA56300D66B1000C65A08000000000000000000000000007BB5A5008CDE
      B50084D6B50084D6AD007BD6AD0073CEA5007BD6AD004AB584004ABD8C0039B5
      7B0094CEB500FFFFFF000000000000000000EFF7F7004A9CDE004A9CDE004A9C
      DE004A9CDE0052A5DE0094C6E700000000000000000000000000FFFFFF00A5CE
      DE0031B5FF0031B5FF0042ADFF00FFFFFF007B84B500317BF700317BF700317B
      F7002973F7001063F700FFFFFF00FFFFFF00FFFFFF00C6D6FF000063F7001063
      F7000863F700005AF7000052EF000000000000000000FF8C3900FFAD6B00FFCE
      A500FFCEA500FFF7EF00FFD6AD00FFD6AD00FFDEBD00FFDEC600FFDEBD00FFC6
      9C00FFB57B00E77B2900B5734200000000000000000000000000000000004AA5
      8400ADEFCE00ADE7CE00A5E7C6009CDEBD008CD6B50073CEA50063C694004ABD
      8C007BCEA500BDD6CE000000000000000000EFF7F7005ABDFF0039B5FF0031B5
      FF0031BDFF0052A5E700000000000000000000000000FFFFFF00DEEFEF0031AD
      F70031BDFF0042BDFF006BADE700FFFFFF00B5BDCE004284FF003984F700397B
      F7004284F700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E7EFFF000063
      F7001063F7001063F700215AD6000000000000000000D68C4A00FFCEA500FFDE
      C600FFD6AD00FFE7CE00FFD6B500FFCEAD00FFCEA500FFCEAD00FFC69C00FFB5
      7300FFC69400F78C3900E7E7DE00000000000000000000000000000000000000
      000052AD8400CEF7DE00BDEFD600B5EFD600ADE7CE00A5DEC60094DEBD007BCE
      AD0063C69C005A9484000000000000000000EFF7F7006BC6FF0063C6FF0063CE
      FF004AC6FF008CBDD600D6E7EF00E7EFF700DEEFEF00C6DEE7004AADE7005AD6
      FF0063D6FF007BDEFF00E7EFF7000000000000000000428CFF004284F700639C
      FF00FFFFFF00FFFFFF00FFFFFF00427BF70094B5F700FFFFFF00FFFFFF00FFFF
      FF00216BF700186BF700BDBDCE000000000000000000FFFFFF00FFBD8C00FFF7
      EF00FFD6B500FFD6B500FFFFFF00FFDEC600FFCEA500FFC69400FFBD8400FFBD
      8400FFC69C00DE7B310000000000000000000000000000000000000000000000
      0000C6E7D60084D6AD00D6F7E700CEF7DE00C6EFDE00B5EFD600ADE7CE0094DE
      BD007BCEAD00318C6B000000000000000000EFF7F7007BCEFF0073CEFF006BD6
      FF0073D6FF0073DEFF005AC6FF0052ADE70052B5EF006BDEFF0073DEFF0073DE
      FF0073DEFF0073BDE700FFFFFF0000000000000000008C9CC6005294FF004A8C
      F70094B5F700FFFFFF00528CF700317BF7003984F7006394F700F7FFFF00528C
      F7002173F7002163EF0000000000000000000000000000000000E7EFCE00FFE7
      D600FFE7D600FFD6B500FFEFDE00FFFFF700FFC69C00FFC69400FFBD8400FFE7
      D600FF944200000000000000000000000000000000000000000000000000A5DE
      C600CEF7DE00E7FFEF00DEFFEF00DEF7EF00D6F7E700CEEFDE00BDEFD600ADE7
      CE0094D6BD0063BD94000000000000000000EFF7F70094DEFF006BADE700A5E7
      FF007BDEFF007BE7FF007BE7FF007BE7FF007BE7FF007BE7FF007BE7FF008CEF
      FF0073BDF70000000000000000000000000000000000000000006384D6005294
      FF004A8CFF003984F700428CF7004284F7004284F7003984F700317BF700317B
      F7002173FF00000000000000000000000000000000000000000000000000E7EF
      DE00FFCEA500FFE7D600FFD6B500FFCEAD00FFE7D600FFCE9C00FFE7CE00EF9C
      5A0000000000000000000000000000000000000000000000000000000000BDE7
      D6008CCEB5007BCEA5007BCEA5008CD6AD00A5DEC600B5E7CE00C6EFD600BDEF
      D600ADE7CE00429C7B000000000000000000FFFFFF006BADE700000000000000
      00007BBDEF00B5F7FF009CF7FF0094EFFF0094F7FF00A5F7FF00A5E7FF00ADD6
      E70000000000000000000000000000000000000000000000000000000000C6CE
      DE00428CFF005294FF005294FF004A8CFF004A8CF700428CFF004284FF006B94
      DE00000000000000000000000000000000000000000000000000000000000000
      000000000000D6CEBD00D6A57B00E7AD7B00DEA57300CEAD8400F7FFF7000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF0000000000000000000000
      00000000000000000000C6DEEF009CCEE700ADD6E700E7F7F700000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000DEE7F7008CB5F70073A5FF007BADFF00BDCEEF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      00000000000000000000000000000000000000000000CECECE00ADADAD009C9C
      9C00A5A5A500ADADAD00ADADAD00CECECE00E7E7E700F7F7F700000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00F7F7F70000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00E7E7E700DEDEDE00D6D6D600DEDE
      DE00EFEFEF00FFFFFF000000000000000000BDB5B50084312900843121008431
      2100843121007B31210084312100844A3900ADADA500DEDEDE00A5A5A5008484
      840094949400C6C6C60094949400000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00E7E7E700DEDEDE00D6D6D600DEDE
      DE00EFEFEF00FFFFFF000000000000000000000000000000000000000000F7F7
      F70063635A006B6B6B0063636300C6C6C600FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00CECECE00A59CAD00AD94CE00AD94DE00A58C
      C600ADA5AD00DEDEDE00FFFFFF0000000000AD9C9C00AD423900AD423900A542
      3100A5423100CEA584008C3929009439310094393100BDBDBD00A5A5A500A5A5
      A500A5949400A57B7B00CECECE00000000000000000000000000000000000000
      00000000000000000000FFFFFF00CECECE00AD9C8C00AD7B5A00A56B4200A57B
      5A00ADA59C00DEDEDE00FFFFFF00000000000000000000000000000000008484
      8400CECEC600CECEC600DEDEDE00C6BDBD005A5A5A007B7B7B00DEDEDE00FFFF
      FF0000000000000000000000000000000000000000000000000000000000FFFF
      FF00E7D6BD00A5948C00FFFFFF007B6BB500D6B5FF00DEB5FF00E7C6FF00CE9C
      F70018189C00ADADB500FFFFFF0000000000EFEFEF00D6635200D6635200D65A
      5200A54A3900F7DEB500C68C7300CE5A4A00CE5A4A0094393100AD5A5200C68C
      7B00CE94840094424200D6D6D60000000000000000000000000000000000FFFF
      FF00E7D6BD00A5948C00FFFFFF00846B520094522900C67B4200BD7342009452
      2900DE947300ADA5A500FFFFFF00000000000000000000000000FFFFFF00D6D6
      CE00DED6D600D6D6CE00D6D6CE00D6CECE00CECEC600E7E7DE00ADADA5004A4A
      4A0094949400E7E7E7000000000000000000000000000000000000000000ADB5
      B500DEBD8400E7CE9C008C738400634ABD00D6B5F700F7EFFF00FFFFFF00F7EF
      FF002121BD0010106B00F7F7F70000000000848484008C5A5200D67B5A00AD5A
      4200EFA58400F7B59400EFA58400D6735A00B5635200EFD6BD00EFD6BD00EFD6
      BD00E7C6B50094393900DEDEDE0000000000000000000000000000000000ADB5
      B500DEBD8400E7CE9C00AD845A00733921008C4A2900E7A55A00F7A55A00BD6B
      3900D6946B008C4A3900F7F7F700000000000000000000000000C6C6C6005A5A
      5A00DEDED600DED6D600DED6D600D6D6CE00D6D6CE00D6D6CE00D6CEC600D6CE
      CE00E7E7DE009C94940052525200FFFFFF000000000000000000DEDEDE00E7A5
      6B00E7CEAD00EFD69C0008085A007B5AE700C694F700F7E7FF00C6ADFF00A58C
      F7002129C60010187300634AD60000000000847B7B006B423900423131003931
      3900314A9C00314A9C0052425A00C6947B00EFCEB500EFCEB500EFCEB500EFCE
      B500E7BDAD008C313100E7E7E700FFFFFF000000000000000000DEDEDE00E7A5
      6B00E7CEAD00EFD69C006B312100311808007B391800BD5A3100DE9C6B00CE94
      6300CE7B5A007B4229005A39210000000000000000000000000073736B00E7E7
      DE00E7DEDE00DEDED600DEDED600DED6D600D6D6CE00D6D6CE00D6D6CE00D6D6
      CE00D6D6CE00CEC6C600DEDED600E7E7E70000000000EFEFEF0084848400A56B
      3900D6A56B00E7BD7B003129B5005A42D600A56BEF003129E7004239EF003129
      DE002121B5001010730021218400000000005A52520010101000101010003952
      8C00395AAD00395AB500395AB500B59C9400DEBDA500DEBDA500DEBDA500DEBD
      A500DEB59C008C292900EFEFEF00FFFFFF0000000000EFEFEF0084848400A56B
      3900D6A56B00E7BD8400180800002910080052211000EF946300F7B57300DE84
      5200B5523900733121004A2118000000000000000000F7F7F70031313100EFE7
      E700E7E7E700E7E7DE0084BD9400219C4A00DED6D600DED6CE00D6D6CE00D6D6
      CE00D6D6CE00CEC6C600DED6D600FFFFFF00FFFFFF00C6C6C600DE9C6300CEA5
      8400BD844A00D69C5A003129B5005239CE008463EF004A4AD600635ADE004242
      CE002121A5001010730021187B00000000002929290010101000181818003973
      D6003973D600397BD600397BD600395A9C00D6A59400D6A59400D6A59400D6A5
      9400D6A58C008C212100EFEFEF00FFFFFF00FFFFFF00C6C6C600DE9C6300CEA5
      8400BD844A00D69C6300180800002108000042181000D6734A00E79C5A00BD5A
      39008C392900843118005221180000000000000000008C8C8C006B846300EFEF
      EF00EFEFE700EFE7E7002994420021944200219C4A0084CE9C00E7DEDE00D6D6
      CE00D6D6CE00D6CEC600BDBDB50000000000FFFFFF00B5ADA500BD9C7300EFCE
      B500E7CEAD00D6B58C002929B5004A42CE00AD9CEF00D6CEFF00CECEEF00B5B5
      E7008C84D60021217B0042319C00EFEFEF00181818001010100021212100428C
      EF00428CEF00428CEF00428CEF003173CE00C68C7B00C68C7B00C68C8400C68C
      8400C68C7B008C212100F7F7F700FFFFFF00FFFFFF00B5ADA500BD9C7300EFCE
      B500E7CEAD00D6B5940021100800291810006B4A4A00AD8C8400DEC6B500C6A5
      9400734A42005A2918007B422900EFEFEF00FFFFFF004A4A4A00297B1800217B
      2100318C3900CEDECE00E7E7DE00DEE7DE008CC69C00219C4A0021A5520029AD
      5A00BDDEC600CECEC600E7E7E7000000000000000000F7D6AD00F7EFD600F7E7
      CE00EFDECE00EFDEC600947BBD007373D600C6C6F700EFEFFF00F7F7FF00E7E7
      F700ADADDE004A4A9400BDBDC600000000002929290010101000181818004A94
      EF004A9CFF00529CFF0052A5FF003973BD00BD7B6B00BD7B6B00BD7B6B00BD7B
      6B00BD736B008C212100F7F7F700FFFFFF0000000000F7D6AD00F7EFD600F7E7
      CE00EFDECE00EFDEC600BD94730052423900A59C9400DED6D600EFE7E700DED6
      CE00AD94840073423900C6C6BD0000000000C6C6C60063636300F7F7F700E7EF
      DE004A944A0021842900218C310063AD6B0084C69400E7E7DE00DEDED60052AD
      730021A55A00D6CECE000000000000000000CEC6B500B5AD9C00FFEFE700F7EF
      E700F7EFE700F7EFDE00F7E7DE008C7BC600D6D6F700F7FFFF00FFFFFF00F7F7
      FF00C6CEDE009C84AD00DEDEDE00000000007363630018181800181818003131
      31004A4A4A004A6B8C005284AD004A393900AD635200AD635200AD635200AD63
      5A00AD6352008C212100F7F7F700F7F7F700CEC6B500B5AD9C00FFEFE700F7EF
      E700F7EFE700F7EFDE00F7E7DE00C69C7300D6CECE00F7F7F700FFFFFF00EFEF
      EF00DECEC600BD9C7B00DEDEDE0000000000C6C6BD00FFFFF700FFF7F700F7F7
      F700F7F7F700F7F7EF00ADCEA50021843100218C3100EFEFEF00E7E7DE00E7DE
      DE00CECEC600BDBDBD00000000000000000000000000FFFFF700FFF7EF00FFF7
      EF00FFF7EF00FFF7EF00FFF7EF00F7EFE700D6CECE00CEC6DE00D6CEEF00C6AD
      CE00AD845A00E7E7E7000000000000000000845A5A004A424200292929005252
      5200847B8400948C94007373730094525200A54A4200A54A4200A54A4200A54A
      4200A54A42008C211800F7F7F700F7F7F70000000000FFFFF700FFF7EF00FFF7
      EF00FFF7EF00FFF7EF00FFF7EF00F7EFE700E7D6C600E7D6C600EFE7D600D6BD
      AD00AD845A00E7E7E7000000000000000000E7DED600F7F7F700FFFFF700FFFF
      F700FFF7F700F7F7F700F7F7EF00C6D6BD00F7EFEF00EFEFE700EFEFE700E7E7
      E700DEDED600FFFFFF0000000000000000000000000000000000F7F7F700FFFF
      FF00FFFFF700FFFFF700FFFFF700FFF7EF00F7EFE700EFE7D600E7D6BD00D6BD
      AD00D6CEC600EFEFEF000000000000000000845A5200EFD6D6008C847B004A4A
      4A007B7B7B006B6B6B009C7B7B00C68C8C00BD847B00B5736B00A55252009C4A
      42009C4242008C211800F7F7F700EFEFEF000000000000000000F7F7F700FFFF
      FF00FFFFF700FFFFF700FFFFF700FFF7EF00F7EFE700EFE7D600E7D6BD00D6BD
      AD00D6CEC600EFEFEF00000000000000000000000000F7F7F700E7DED600DEDE
      D600FFFFFF00FFF7F700F7F7F700F7F7F700F7F7EF00F7EFEF00EFEFE700DEDE
      D600ADADAD000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFF700F7F7EF00EFE7DE00E7DECE00DEC6
      B500F7F7F70000000000000000000000000084635A00A55A5200BD848400D6B5
      AD00EFD6D600E7D6CE00E7C6C600DEBDBD00D6ADAD00CE9C9C00C6948C00BD84
      8400B57373008C211800F7F7F700EFEFEF000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFF700F7F7EF00EFE7DE00E7DECE00DEC6
      B500F7F7F7000000000000000000000000000000000000000000000000000000
      0000F7F7F700DEDED600DEDEDE00FFF7F700F7F7F700F7F7EF00F7EFEF00DED6
      D600F7F7F7000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00F7F7F700F7F7EF00EFEFE700EFDED600FFFF
      F700FFFFFF0000000000000000000000000000000000FFFFFF00C6C6C600B5B5
      B500B5B5B500B5B5B500A5848400945252008C31310094393100AD5A5A00BD7B
      7B00C69494008C211800F7F7F700EFEFEF000000000000000000000000000000
      00000000000000000000FFFFFF00F7F7F700F7F7EF00EFEFE700EFDED600FFFF
      F700FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F7F7EF00D6D6CE00E7E7DE00D6D6CE00D6CE
      CE00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00F7F7F700F7EFEF00EFEF
      EF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000EFEFEF00C6C6C600BDBDBD00DEDE
      DE00D6D6D600BDADAD00F7F7F700000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00F7F7F700F7EFEF00EFEF
      EF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFF7F7000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00CECECE00E7E7E700FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000E7E7E700216329008484840063636300DEDEDE00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00E7E7E700DEDEDE00D6D6D600DEDE
      DE00EFEFEF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00E7E7E700DEDEDE00D6D6D600DEDE
      DE00EFEFEF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00E7E7E700DEDEDE00D6D6D600DEDE
      DE00EFEFEF00FFFFFF0000000000000000000000000000000000000000000000
      00008C8C8C0084F794005AE77300D6D6D600E7E7E70063636300DEDEDE00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00CECECE008CADAD0073CED60063D6DE0073C6
      CE009CADAD00DEDEDE00FFFFFF00000000000000000000000000000000000000
      00000000000000000000FFFFFF00CECECE008CAD9C0094D6A50094DEB5008CCE
      9C009CADA500DEDEDE00FFFFFF00000000000000000000000000000000000000
      00000000000000000000FFFFFF00CECECE00B5B5B500D6D6D600DEDEDE00CECE
      CE00ADADAD00DEDEDE00FFFFFF0000000000000000000000000000000000F7F7
      F700298C310073F78C004AEF630029CE420029943900D6D6D600DEDEDE006B6B
      6B00E7E7E700000000000000000000000000000000000000000000000000FFFF
      FF00E7D6BD00A5948C00FFFFFF007BADBD005AE7F70063EFF7006BF7FF0052EF
      F70010395200ADBDBD00FFFFFF0000000000000000000000000000000000FFFF
      FF00E7D6BD00A5948C00FFFFFF0073BD8C00B5FFD600B5FFE700C6FFEF009CFF
      DE00296B2100ADBDB500FFFFFF0000000000000000000000000000000000FFFF
      FF00E7D6BD00A5948C00FFFFFF00ADADAD00EFEFEF00F7F7F700FFFFFF00EFEF
      EF009C9C9C00BDBDBD00FFFFFF0000000000000000000000000000000000BDBD
      BD0073EF840063F7840031DE4A0029BD390029A5390029A5390029843900E7E7
      E700D6D6D60073737300E7E7E70000000000000000000000000000000000ADB5
      B500DEBD8400E7CE9C009CA58C00429CAD009CEFF700EFFFFF00FFFFFF00DEFF
      FF00296B840010314200F7F7F70000000000000000000000000000000000ADB5
      B500DEBD8400E7CE9C0094AD730052B56B00B5F7DE00EFFFF700FFFFFF00EFFF
      F70031943100184A1800F7F7F70000000000000000000000000000000000ADB5
      B500DEBD8400E7CE9C00BDAD8C00A5A5A500EFEFEF00FFFFFF00FFFFFF00FFFF
      FF00A5A5A5006B6B6B00F7F7F700000000000000000000000000FFFFFF00426B
      4A007BEF8C0052EF6B0029CE420029AD390029A53900299C3900299439004294
      52004A7B5200EFEFEF00C6C6C600000000000000000000000000DEDEDE00E7A5
      6B00E7CEAD00EFD69C002139420073D6EF00C6EFF700F7FFFF00CEFFFF00B5EF
      F700428C9C00294A5A0073CEEF00000000000000000000000000DEDEDE00E7A5
      6B00E7CEAD00EFD69C00104210005AE77B0094F7CE00E7FFF700B5FFC6009CF7
      AD00319C3100185A180052DE7300000000000000000000000000DEDEDE00E7A5
      6B00E7CEAD00EFD69C004A4A4A00B5B5B500EFEFEF00FFFFFF00F7F7F700E7E7
      E700A5A5A5006B6B6B00A5A5A500000000000000000000000000DEDEDE004ADE
      63006BF7840031DE4A0029BD390029A5390029A53900299C3900298C39005A9C
      63007BAD840094B59C00BDBDBD000000000000000000EFEFEF0084848400A56B
      3900D6A56B00E7BD7B005AB5D6007BD6E700C6EFF7007BDEDE008CE7EF0073D6
      DE00528CA500315A6B00427384000000000000000000EFEFEF0084848400A56B
      3900D6A56B00E7BD7B0029B5420042D663006BEF9C0042DE42004AE7520042D6
      420029942900185A1800217329000000000000000000EFEFEF0084848400A56B
      3900D6A56B00E7BD7B00737373009C9C9C00CECECE00BDBDBD00C6C6C600B5B5
      B50094949400636363005A5A5A000000000000000000000000007B7B7B007BEF
      940052EF6B0029CE420021AD3900299C3900299C390029943900318C39006BA5
      730094BD9C00E7EFE7000000000000000000FFFFFF00C6C6C600DE9C6300CEA5
      8400BD844A00D69C5A0063BDDE0084D6EF00BDEFF7008CC6CE00A5D6DE0084C6
      CE005A94A50039636B004273840000000000FFFFFF00C6C6C600DE9C6300CEA5
      8400BD844A00D69C630029B5390039CE520063EF840052C652006BD66B004ABD
      4A00298C2900185A1800186B290000000000FFFFFF00C6C6C600DE9C6300CEA5
      8400BD844A00D69C5A007373730094949400BDBDBD00BDBDBD00CECECE00ADAD
      AD00848484005A5A5A00525252000000000000000000F7F7F700299C39006BEF
      840039DE4A0029B53900219C3900299C390029943900298C31005AA56B0084B5
      8C00A5C6AD00FFFFFF000000000000000000FFFFFF00B5ADA500BD9C7300EFCE
      B500E7CEAD00D6AD8C007BCEEF009CDEEF00D6F7FF00EFFFFF00E7EFF700D6E7
      E700BDDEDE00527B840073A5B500EFEFEF00FFFFFF00B5ADA500BD9C7300EFCE
      B500E7CEAD00D6AD940029B5390042CE52009CEFAD00CEFFD600CEE7CE00BDDE
      BD0084D68C00216B2900319C4A00EFEFEF00FFFFFF00B5ADA500BD9C7300EFCE
      B500E7CEAD00D6AD94006B6B73008C8C8C00D6D6D600EFEFEF00EFEFEF00DEDE
      DE00BDBDBD005A5A5A007B7B7B00EFEFEF0000000000ADADAD007BEF8C005AE7
      6B0029BD3900219C3100219C3100219C3100218C3100298431007BAD840094B5
      9C00C6C6C60000000000000000000000000000000000F7D6AD00F7EFD600F7E7
      CE00EFDECE00EFDEC600ADD6CE00BDEFF700EFFFFF00FFFFFF00FFFFFF00F7FF
      FF00D6E7EF0084A5AD00C6CEC6000000000000000000F7D6AD00F7EFD600F7E7
      CE00EFDECE00EFDEC60094CE940073D67B00C6F7C600EFFFEF00F7FFF700E7F7
      E700ADDEB5004A844A00C6CEC6000000000000000000F7D6AD00F7EFD600F7E7
      CE00EFDECE00EFDEC600C6BDB500A5A5A500DEDEDE00F7F7F700F7F7F700EFEF
      EF00CECECE0073737300CECEC60000000000FFFFFF004A7B52006BE7840039CE
      520021A539002194310021943100218C3100218431005A9C630094BD9C00DEE7
      E700FFFFFF00000000000000000000000000CEC6B500B5AD9C00FFEFE700F7EF
      E700F7EFE700F7EFDE00F7E7DE00B5D6DE00F7FFFF00FFFFFF00FFFFFF00FFFF
      FF00E7EFEF00A5BDBD00DEDEDE0000000000CEC6B500B5AD9C00FFEFE700F7EF
      E700F7EFE700F7EFDE00F7E7DE0084CE9C00D6F7D600F7FFFF00FFFFFF00F7FF
      F700C6DEC6009CBD9C00DEDEDE0000000000CEC6B500B5AD9C00FFEFE700F7EF
      E700F7EFE700F7EFDE00F7E7DE00BDBDBD00E7E7E700FFFFFF00FFFFFF00F7F7
      F700D6D6D600BDB5AD00DEDEDE0000000000000000005AE7730063E7730029B5
      390021943100218C3100218C310021843100217B310084B58C00A5BDA500F7F7
      F700FFFFFF0000000000000000000000000000000000FFFFF700FFF7EF00FFF7
      EF00FFF7EF00FFF7EF00FFF7EF00F7EFE700DEDED600CEE7EF00D6F7F700C6D6
      D600AD846300E7E7E700000000000000000000000000FFFFF700FFF7EF00FFF7
      EF00FFF7EF00FFF7EF00FFF7EF00F7EFE700DEDECE00D6EFDE00DEF7E700C6DE
      C600AD846300E7E7E700000000000000000000000000FFFFF700FFF7EF00FFF7
      EF00FFF7EF00FFF7EF00FFF7EF00F7EFE700EFDED600EFE7E700F7F7F700DED6
      CE00AD846300E7E7E70000000000000000000000000084E78C0042C65200299C
      3900298C3100218C310021843100217B31006BA5730094B59400F7F7F700F7F7
      F700000000000000000000000000000000000000000000000000F7F7F700FFFF
      FF00FFFFF700FFFFF700FFFFF700FFF7EF00F7EFE700EFE7D600E7D6BD00D6BD
      AD00D6CEC600EFEFEF0000000000000000000000000000000000F7F7F700FFFF
      FF00FFFFF700FFFFF700FFFFF700FFF7EF00F7EFE700EFE7D600E7D6BD00D6BD
      AD00D6CEC600EFEFEF0000000000000000000000000000000000F7F7F700FFFF
      FF00FFFFF700FFFFF700FFFFF700FFF7EF00F7EFE700EFE7D600E7D6BD00D6BD
      AD00D6CEC600EFEFEF0000000000000000000000000000000000B5DEBD002984
      31002984310029843100297B310042844A0094B59400E7EFE700F7F7F700FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFF700F7F7EF00EFE7DE00E7DECE00DEC6
      B500F7F7F7000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFF700F7F7EF00EFE7DE00E7DECE00DEC6
      B500F7F7F7000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFF700F7F7EF00EFE7DE00E7DECE00DEC6
      B500F7F7F7000000000000000000000000000000000000000000000000000000
      0000A5C6A500297B31003984420084AD8C00BDCEBD00DEDEDE00C6C6C6000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00F7F7F700F7F7EF00EFEFE700EFDED600FFFF
      F700FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00F7F7F700F7F7EF00EFEFE700EFDED600FFFF
      F700FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00F7F7F700F7F7EF00EFEFE700EFDED600FFFF
      F700FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000094B59C008CAD94000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00F7F7F700F7EFEF00EFEF
      EF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00F7F7F700F7EFEF00EFEF
      EF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00F7F7F700F7EFEF00EFEF
      EF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E7E7E70000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF009C9C9C008484
      8400848484008484840084848400848484008484840084848400848484008484
      8400848484008C8C8C00E7E7E7000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00F7F7F700FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000FFFFFF00CECECE00E7E7E700FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000D6CECE00B56B4A00D68C63009C6B5200FFFFFF000000
      00000000000000000000000000000000000000000000F7F7F700CECECE00E7E7
      E700DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDEDE00DEDE
      DE00DEDEDE00DEDEDE00C6C6C60000000000FFFFFF00F7F7F700E7E7E700D6D6
      D600DEDEDE008C636300A5311000C6311000BD3110009C392100A5949400DEDE
      DE00DEDEDE00EFEFEF00F7F7F700000000000000000000000000000000000000
      0000E7E7E70021216B008484840063636300DEDEDE00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C6BDBD00D6844A00E7AD7300E7AD7300E7AD7300E7AD7300DE8C5200C6BD
      BD000000000000000000000000000000000000000000F7F7F700D6D6D600FFF7
      EF00F7EFE700D6D6D600D6D6D600EFEFEF00D6D6D600DEDEDE00D6D6D600D6D6
      D600D6D6D600D6D6D600C6C6C60000000000000000000000000000000000DEAD
      A500DE521800E7632100DE4A1800D6421800D6391800D6391800EF4A2100CE31
      1000FFF7F7000000000000000000000000000000000000000000000000000000
      00008C8C8C008484FF004A4AEF00D6D6D600E7E7E70063636300DEDEDE00FFFF
      FF00000000000000000000000000000000000000000000000000C6BDB500D694
      6300F7C68C00F7C68C00F7C68C00F7C68C00EFBD8C008473DE004A4AFF00735A
      BD009C735A00FFFFFF00000000000000000000000000F7F7F700D6D6D600FFF7
      EF00F7EFE700D6D6D600FFFFFF00FFFFFF00FFFFFF00FFFFFF00F7F7F700D6BD
      A500DE8C4200D6843900948C7B00EFEFEF000000000000000000CE7B7300E773
      2900E7632100DE632100C64A2900ADADAD00AD7B7300D6391000D6311800CE31
      1800E7391800F7EFE7000000000000000000000000000000000000000000F7F7
      F70021299C006B6BF7004242FF002129FF002121C600D6D6D600DEDEDE006B6B
      6B00E7E7E70000000000000000000000000000000000CE633900FFDE9C00FFDE
      9C00FFDE9C00FFDE9C00E7D6940031E708002952CE005252FF004A4AFF000000
      EF00D6BDAD00F7BD7B00DED6D6000000000000000000F7F7F700D6D6D600FFF7
      EF00F7EFE700EFEFEF00FFFFFF00FFFFFF00CECECE00D6D6D600F7E7CE00D684
      3100D6843900D67B2900D6843100948C840000000000EFCECE00EF7B2900E76B
      2100E76B2100E7632100B59C9400BDB5B500C6422100B5847B00D6421800D639
      1800CE291000D63118000000000000000000000000000000000000000000BDBD
      BD007373FF005A5AFF002129FF002121F7002121DE002121DE002929B500E7E7
      E700D6D6D60073737300E7E7E7000000000000000000CE7B5200DEA57B00E7B5
      8C00F7D6A500F7B5520042BD290029E70000295ABD005252FF004A4AFF000000
      EF00B5737300D6946B00EFD6C6000000000000000000F7F7F700D6D6D600FFF7
      EF00EFEFE700EFEFEF00FFFFFF00DEDEDE00D6D6D600D6D6D600EFA56300D684
      3100E7B58C00F7D6B500D6843100CE8C4A0000000000C6521800EF842900E773
      2100E76B2100E76B2100BD6B5200CED6D600D6421000BD8C8400C64A2900D639
      1800D6391800E7422100CE847300000000000000000000000000FFFFFF004242
      6B007373F7004A4AFF002129FF002121E7002121DE002121DE002121CE004242
      C6004A4A9C00EFEFEF00C6C6C6000000000000000000D6845A00E7B59400E7B5
      9400D68C4A00F7AD4A004ABD290029E700002963B5005252FF007373FF000000
      EF00BD949400DEAD8400F7D6CE000000000000000000F7F7F700D6D6D600FFF7
      EF00F7EFE700CECECE00FFFFFF00EFEFEF00D6D6D600D6D6D600FFC68C00E794
      4200F7D6B500F7D6B500E7944200D6945200FFF7F700F7A53100EF8C2900EF7B
      2900E76B2100E76B2100D6521000D6DEDE00C6736300DE4A1800C64A2900D642
      1800D6391800CE311800CE391000000000000000000000000000DEDEDE004A4A
      EF005A63FF002929FF002121EF002121DE002121DE002121D6002121C6005252
      C6007B7BCE009494CE00BDBDBD000000000000000000D6846300E7BD9C00E7BD
      9C00D68C4A00F7AD4A0052BD290029E7000052BD73006B6BFF00A5A5F700736B
      DE00D6AD9C00E7B59400F7DECE000000000000000000F7F7F700DEDEDE00FFF7
      F700F7EFE700CECECE00EFEFEF00EFEFEF00DEDEDE00DEDEDE00FFFFF700EFA5
      5200E7944200E7944200F7A55200CEC6C600DEA59C00FFAD3100F7942900EF8C
      2900EF7B2100C66B5200EF631800D6CECE00D6D6D600DE521800D6521800D64A
      1800D6421800D6391800E74A21000000000000000000000000007B7B7B007B7B
      FF004A52FF002129FF002121DE002121D6002121D6002121CE002931BD006B6B
      CE009494D600E7E7EF00000000000000000000000000D68C6B00EFCEB500EFCE
      B500D68C4A00F7AD4A0052BD290029E7000029D6210029AD0000E7C6A500E7C6
      A500E7C6A500E7C6A500F7DED6000000000000000000F7F7F700E7E7E700FFFF
      F700F7EFEF00EFEFEF00F7F7F700FFFFFF00E7E7E700E7E7E700E7E7E700FFFF
      F700FFD6B500F7CEAD00BDB5B500FFFFFF00CE847B00FFB53900F79C3100F794
      2900EF942900D6A58C00CE5A3100CE7B5A00EFF7FF00CE4A1000DE521800D64A
      1800D64A1800D6421800DE4A21000000000000000000F7F7F7002929AD006363
      FF003131FF002121E7002121D6002121D6002121CE002121BD005A5AC6008484
      CE00A5A5D600FFFFFF00000000000000000000000000DE947300EFD6C600EFD6
      C600D68C5200F7AD4A005ABD290029E7000031DE210029AD0000EFCEBD00EFCE
      BD00EFCEBD00EFCEBD00F7DED6000000000000000000F7F7F700E7E7E700FFFF
      F700F7F7EF00E7E7E700E7E7E700EFEFEF00F7F7F700F7F7F700FFFFFF00EFEF
      EF00EFEFEF00EFEFEF00C6C6C60000000000DEA59C00FFC64200F7A53100F79C
      3100F7942900EF8C2100F7E7EF00CE4A0000FFFFFF00CE633900DE521800DE52
      1800D64A1800D6421800D64A18000000000000000000ADADAD007B7BFF005252
      FF002129EF002121D6002121CE002121CE002121BD002121B5007B7BCE009494
      CE00C6C6C60000000000000000000000000000000000DE9C7B00F7DED600F7DE
      D600D68C5200F7AD4A0084CE420031E7000031CE00005ACE3100F7DECE00F7DE
      CE00F7DECE00F7DECE00F7DED6000000000000000000F7F7F700E7E7E700FFFF
      FF00F7F7EF00EFEFEF00EFEFEF00EFEFEF00E7E7E700DEDEDE00DEDEDE00E7E7
      E700E7E7E700E7E7E700CECECE0000000000FFF7F700FFD64A00FFAD3100F7A5
      3100F79C3100F7942900E77B1800E7C6BD00EFC6BD00E76B1800E76B2100E763
      2100DE5A2100DE521800C639100000000000FFFFFF004A4A7B006B6BF7003939
      F7002121D6002121C6002121C6002121BD002121B500525ABD009494CE00DEDE
      E700FFFFFF0000000000000000000000000000000000EFCEC600EFBDA500F7EF
      E700D6945A00F7AD4A00FFA51800C67B0800E7EFCE00F7E7DE00F7E7DE00F7E7
      DE00F7E7DE00EFBD9400F7EFE7000000000000000000F7F7F700E7E7E700FFFF
      FF00F7F7EF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00F7A55200F7A5
      5200F7A55200B5947300FFFFFF000000000000000000C66B2900FFB53100FFAD
      3100F7A53100F79C3100F7942900D6733900E7C6BD00DE632100E7732100E76B
      2100E7632100E7632100CE84730000000000000000005A5AF7005A5AF7002121
      D6002121BD002121BD002121BD002121B5002121A5008484CE00A5A5CE00F7F7
      F700FFFFFF00000000000000000000000000000000000000000000000000EFC6
      B500D68C5200F7AD4A00FFA51800C67B0000FFF7EF00FFF7EF00F7CEB500E7A5
      8400FFFFFF0000000000000000000000000000000000F7F7F700E7E7E700FFFF
      FF00F7EFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00FFB56300FFAD
      6300B5947300FFFFFF00000000000000000000000000EFCECE00FFE75200FFB5
      3100FFAD3100F7A53100F79C2900EFD6D600F7F7F700EFD6D600EF842900E773
      2100E76B2100C64210000000000000000000000000007B84F7004242E7002121
      C6002121B5002121B5002121AD002121A5006B6BBD008C94CE00F7F7F700F7F7
      F700000000000000000000000000000000000000000000000000000000000000
      0000DE9C6300F7AD4A00F7A52100C67B0000E7A57B00FFF7EF00000000000000
      00000000000000000000000000000000000000000000F7F7F700E7E7E700FFFF
      FF00EFEFE700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00FFD6B500B5A5
      8C00FFFFFF000000000000000000000000000000000000000000CE7B7300FFEF
      5200FFB53100FFAD3100F7A53100DE7B3100F7E7EF00D6845A00EF842900EF7B
      2900D6631800F7EFE70000000000000000000000000000000000B5B5E7002121
      AD002121AD002121AD002121A5004242AD008C94C600E7E7EF00F7F7F700FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000EFC69C00DE8C3100EF941800F7B552000000000000000000000000000000
      00000000000000000000000000000000000000000000F7F7F700E7E7E700E7E7
      E700EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00EFEFEF00BDA59400FFFF
      FF0000000000FFFFFF00FFFFFF0000000000000000000000000000000000DEAD
      AD00E7AD3900FFD64200FFAD3100F7A53100F79C2100F79C3100F79C3100BD4A
      1800FFF7F7000000000000000000000000000000000000000000000000000000
      00009C9CD6002121A5003939A5008484C600BDBDD600DEDEDE00C6C6C6000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFF700000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00F7F7
      F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000D69C9400BD633900CE6B2900C6632900BD5A4200EFCECE000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000009494C6008C8CBD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00CECECE00E7E7E700FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00CECECE00DEDEDE00EFF7F700FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F7EFE700F7EFE700F7EFE700F7EF
      E700F7EFE700F7EFE700F7EFE700F7EFE700FFEFE700FFEFE700FFEFE700FFF7
      E700FFF7E700FFF7E700FFF7E700FFFFFF000000000000000000000000000000
      0000E7E7E7006B4221008484840063636300DEDEDE00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF004A4A4A0039C6E70039BDEF005A9CAD00DEDEDE00EFE7
      E700CEBDBD00BDB5AD000000000000000000000000009C4210009C4210009C42
      10009C4210009C421000A54A1000AD521000B5631000BD731000CE7B1000D68C
      1000E7941000EF9C1000F7A51000F7F7EF0094390800DEBDB500DEC6B500E7C6
      B500E7C6B500E7C6B500E7CEB500EFCEB500EFCEAD00EFCEAD00F7D6AD00F7D6
      AD00FFDEAD00FFDEAD00FFDEAD00FFFFF7000000000000000000000000000000
      00008C8C8C00FFCE8C00EFC67300D6D6D600E7E7E70063636300DEDEDE00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00EFEFEF0063ADB50063DEFF0063DEFF0052D6F700736B6300CECE
      BD00F7EFDE00DED6C600B5ADA500FFFFFF000000000094310000CE8C8400D694
      8400DE947B00D6947300D6DEC6008CBD84008CBD84008CBD8400FFFFFF008C8C
      BD008C84C6008C84C6009C94C6000000000094390800DEADAD009C635A00F76B
      0800F76B0800EFADA500F76B2100F7731800F7731800E76B1800FFEFE700F76B
      1000F76B1000F76B1000DE73520000000000000000000000000000000000F7F7
      F7009C5A2900F7D68400F7BD5A00E7843100BD632900D6D6D600DEDEDE006B6B
      6B00E7E7E700000000000000000000000000D6CEC600B5A59C009C8C7B00BDAD
      9C00DED6C600DECEC6008CD6E70084EFFF0084EFFF0052DEFF0010101000736B
      6B00B5A59C00B59C9400DECEC600EFEFEF00000000009439000000B5FF009C73
      7300FF7B2100E76318009CD6A50021C6520021C6520021C65200F7FFFF000821
      FF000018FF000018FF002931B5000000000094390800299CF70008C6FF00D67B
      4A00FF843100E7B5B500FF946300FFA56300FFA56300EF9C6300FFEFE700FF8C
      4200FF8C4200FF8C4200DE7B630000000000000000000000000000000000BDBD
      BD00FFBD7B00FFD67B00EFA54200DE733100D6632900D6632900B55A3100E7E7
      E700D6D6D60073737300E7E7E70000000000F7F7EF00F7F7EF00E7E7D600EFEF
      DE00DED6CE00C6B5AD009C9494007BD6E7007BC6CE008CFFFF0052E7FF000818
      2100736B6B00E7DED600CEBDB500EFEFEF000000000094310000428CCE0008D6
      FF00BD8C730010CEFF0084BDAD0031DE840031DE840031DE8400F7FFFF00084A
      FF000042FF000042FF002939B5000000000094390800E7B5B50010D6FF0010DE
      FF0021C6F70010E7FF00FFBDAD00FFD6BD00FFD6BD00EFC6AD00FFEFEF00FFAD
      7B00FFAD7B00FFAD7B00DE847300000000000000000000000000FFFFFF006B52
      4200F7D68400F7C66300EF8C3100DE6B2900D6632900D6632900CE5A2900CE6B
      4200AD6B5200EFEFEF00C6C6C60000000000B5A59C00D6CEC600CEBDBD00FFF7
      EF00FFF7EF00FFF7EF00F7F7EF00E7DED6004A4242007BADB50094FFFF005AEF
      FF001029310073736B00BDADA500EFEFEF000000000094390000FF9C7B0031C6
      EF0018F7FF0018F7FF0018EFFF0042EFAD0042F7AD0042F7AD00F7FFFF000873
      FF000073FF000073FF00294AB500000000009C420800EFB5AD00F7BD940018F7
      FF0018F7FF0018EFFF0021E7FF00FFF7F700FFFFF700EFEFE700FFEFEF00FFD6
      B500FFD6B500FFD6B500DE948400000000000000000000000000DEDEDE00EF9C
      5200FFD67B00EF9C4200DE733100D6632900D6632900D6632900CE5A2900D67B
      5A00DE947B00DEA59400BDBDBD0000000000E7DED600FFFFF700BDADA500FFFF
      F700FFFFF700F7F7EF00E7D6D600E7DEDE00C6BDB5005A5252006394940094FF
      FF005AEFFF0018394200635A5A00E7E7E700000000009C420000FFB59C00FFD6
      BD0021DEFF00DEAD9C0021DEFF0018F7FF0063FF310063FF3100F7FFFF00089C
      FF0010CEFF00009CFF00295AB50000000000A54A0800F7BDAD00FFDEC600EFCE
      C600A5BDDE00D6B5BD0018FFFF0029D6FF00FFDEB500EFCEA500FFEFEF00D6CE
      E70018F7FF00FFEFE700D69C94000000000000000000000000007B7B7B00FFCE
      8400F7BD6300E7843100DE6B2900D6632900D6632900CE5A2900CE5A3100D68C
      7300DEA59400EFEFE7000000000000000000B5A59C00BDADA500A58C8400DED6
      CE00F7EFE700FFFFF700DECECE00FFFFF700FFFFF700FFF7EF006B636300526B
      73009CFFFF008C8C8C004A4A6B00E7E7E70000000000AD520000FFC6BD00FFEF
      E700FFEFE700E7C6BD00A5DEAD0018E7FF0018DEF7004ACE0000EFF7F70010E7
      FF0018F7FF0010DEFF00296BB50000000000AD520800F7BDB500FFF7EF00FFF7
      EF00FFF7EF00E7C6C600D6947B0018EFFF004AB5DE00EFAD6300B5C6F70018EF
      FF0018F7FF0018DEFF00CE9CA5000000000000000000F7F7F700AD6B2900F7C6
      7300EF944200DE6B2900D6632900D6632900D65A2900CE5A2900D6846300DE9C
      8400DEB5A500FFFFFF000000000000000000C6B5B500FFFFF700C6B5AD00FFFF
      F700FFFFF700FFFFF700C6B5B500FFFFF700FFFFF700FFFFF700BDADA500BDBD
      B50073737300DEDEE700846BD600E7E7E70000000000B5630000FFCEC600FFFF
      F700FFFFF700E7CECE00ADDEA5004ACE000008CEFF0008BDF70008D6FF0008C6
      FF0000DEFF0008CEFF0018B5FF0000000000B5630800F7BDB500FFFFFF00FFFF
      FF00FFFFFF00EFC6BD00FF9C5A00B59C840008D6FF00399CDE0008D6FF0042B5
      EF00EFCEB50008D6FF0029A5F7000000000000000000ADADAD00F7BD7B00F7AD
      6300E7732900D65A2900D65A2900D65A2900CE5A2900C6522900DE947B00DEA5
      9400C6C6C600000000000000000000000000DED6CE00BDADAD00AD948C00BDAD
      A500BDADA500C6B5AD00A58C8C00DED6CE00EFE7DE00F7EFEF00CEBDBD00FFFF
      F700ADA5C600947BB5007B6B7300E7E7E70000000000C6730000FFB59C00FFDE
      B500FFDEB500E7B59400EFEFE700BDE7C600B5E7CE0000BDFF00319CFF0008A5
      FF0000A5FF0000A5FF00295ABD0000000000C6730800F7C6AD00FFDEBD00FFDE
      BD00FFDEBD00EFC6BD00F7CEBD00EFCEC60094ADE70000BDFF007B94DE00FFBD
      7B00FFBD7B00E7B58400BD8C8C0000000000FFFFFF007B634A00F7B57300EF84
      4200D6632900CE5A2900D65A2900CE5A2900CE522900D67B5A00DEA59400E7E7
      DE00FFFFFF00000000000000000000000000EFE7E700FFFFF700E7DED600FFFF
      F700FFFFF700FFFFF700B5A5A500FFFFF700FFFFF700FFFFF700DED6D600FFFF
      F700FFFFF700FFFFF700AD948C00E7E7E70000000000D6840000FFA57B00FFC6
      8400FFC68400E79C6B00000000000000000000000000F7FFFF00000000000873
      FF00006BFF00006BFF00294AB50000000000CE840800FFBDAD00FFC68C00FFC6
      8C00FFC68C00F7BDB500000000000000000000000000C6CEFF00F7EFEF00FFAD
      5A00FFAD5A00FFAD5A00DE8C6B000000000000000000F7A56300F7A56300DE63
      2900CE522100CE5A2900CE5A2900CE522900C6522900DE9C8400DEB5A500F7F7
      F700FFFFFF00000000000000000000000000F7F7F700947B63008C735A00846B
      5A00846B5200846B52007B634A007B634A00846B5200846B520084735A008C73
      5A008C7B6300947B630084735A00E7DEDE0000000000DE8C0000FF9C5A00FFB5
      5A00FFB55A00E7944A0000000000000000000000000000000000000000000831
      FF000029FF000029FF002931B50000000000DE8C0800FFBDA500FFB56300FFB5
      6300FFB56300EFBDAD0000000000000000000000000000000000FFEFEF00FFAD
      5A00FFAD5A00FFAD5A00DE8C6B000000000000000000F7B58400E77B4A00D65A
      2900CE522900CE522900C6522100C6522900D68C7300DEA59400F7F7F700F7F7
      F70000000000000000000000000000000000FFFFFF00CEBDAD00CEBDAD00846B
      6300CEBDAD008C7B6B00C6ADA500C6B5AD00947B7300CEBDAD00A59484008C73
      6B00CEBDAD00CEBDAD00C6B5A500DEDEDE0000000000EF9C0000FF945A00FFAD
      5A00FFAD5A00E78C4A000000000000000000000000000000000000000000BDBD
      EF00B5BDEF00B5B5EF00949CDE0000000000E79C0800FFC6A500FFAD5A00FFAD
      5A00FFAD5A00EFBDAD0000000000000000000000000000000000FFEFEF00FFC6
      9400FFC68C00FFC68C00E78C7300000000000000000000000000EFC6B500CE52
      2900CE522900CE522900C6522900C6634200DEA59400EFEFE700F7F7F700FFFF
      FF0000000000000000000000000000000000000000009C847300A58C7B00947B
      6B00A58C7B00B59C8C00A58C7B00AD9484008C736B00A58C7B00BDA59C009484
      7300A58C7B00A58C7B00A58C7B00FFFFFF0000000000F7A50000FF945A00FFAD
      5A00FFAD5A00E78C4A0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F7A50800FFC6A500FFAD5A00FFAD
      5A00FFAD5A00EFBDAD0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000E7B5A500C6522900C65A3900DE9C8400DEC6BD00DEDEDE00C6C6C6000000
      0000000000000000000000000000000000000000000000000000E7DED600ADA5
      A500BDB5B5009C8C8400A58C8400D6C6C600ADA59C009C8C8400C6B5AD00A59C
      9400BDB5AD00EFE7E700F7EFEF000000000000000000FFA50000FFDECE00FFDE
      CE00FFDED600FFD6CE0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFA50800FFCEAD00FFBD8400FFBD
      8400FFBD8400F7BDAD0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000D6AD9400D6A594000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00C6B5
      B500FFFFFF00DED6CE00C6BDB500FFFFFF00C6B5B500F7F7F700EFEFE700BDA5
      A500FFFFFF0000000000000000000000000000000000FF9C0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFCE7300FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000A00000000100010000000000000500000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFFFF9C003C0038001FFF080018001
      800103C080018001FE7F0180C001C001F00F0001C003C003E0078001C003C003
      C007800780018001C003800780018001C003000780018001C003000380018001
      C003000780018001C003000FC001C001C003000FC003C003E007801FE007E007
      F00FC03FF00FF00FF81FE0FFFC3FFC3FFFFF801FFFFFFC07F81F800FF03FE003
      E0078007E003C001C0038003F005800080038001FE03800080018001C003C000
      80018001E007C00080018001F007800080018001E007800180018001E0078001
      80018001C007800180038001E0078003C0038001E007C003E0078001E00FE003
      F00F8001F01FF00FFFFF8001FC3FF83FFC3FFFFFC007F99FF00FFFFFC003C003
      E0078001C003F00FE0078001C003E007E0078001C003C003F00F8001C0038001
      F00F8001C0038001F00F8001C0038001F00F8001C0038001F00F800180038001
      F00F800180038001F00F80018003C003F00F8001C003C007F00F8001C003E00F
      FFFFFFFFC003F81FFFFFFFFFC003FFFFFFFF0000FFFFFC3FFC0F00000FF0F00F
      3003000003C0E007000100000000E007800000000003E007C00000008007F00F
      C0000000C003F00FC0000000D003F00FC0000000F847F00FC0000000F03FF00F
      C0000000E207F00FC0010000CF07F00FE00100009F07F00FF0030000FF07F00F
      F8070000FF07FFFFFE1F0000FF9FFFFFF803FFFFFFFFFFFFE003F9FFFFF7F83F
      C001E07FFFE3E00F8000C03FFFC1C0070001C01FFF8180030001800FFFC08001
      80018007FFC0000180018007FFE000010001C00700E000010001C00301C00001
      8001E003038000018001F003000180018003F00300018003C007E0030007C007
      E00FE003300FE00FF81FFFFF7C3FF83FFFDF803BFFDFF3FFFE030001FE03E07F
      FC010001FC01E00FE0010001E001C003E0010001E001C000C0010000C001C000
      8001000080018000000100000001800100000000000000018001000080010003
      00010000000100038003000080030003C0030000C0038007F0070000F007F007
      FC078000FC07FE0FFF0FFF01FF0FFFDFF0FFFFDFFFDFFFDFF03FFE03FE03FE03
      F00FFC01FC01FC01E007E001E001E001E001E001E001E001C001C001C001C001
      C001800180018001C00300010001000180030000000000008007800180018001
      00070001000100018007800380038003800FC003C003C003C00FF007F007F007
      F01FFC07FC07FC07FCFFFF0FFF0FFF0FFF7F80018001F0FFFC1F80010001F03F
      F00F8001E007F00FC0038000C003E007800180008003E001800180008001C001
      800180000001C001800180000001C00380018000000180038001800100018007
      80018001000100078001800180018007E00780038003800FF03F8007C003C00F
      F0FF8009E007F01FFDFFC01FF81FFCFFF0FFF83FFFFF0000F03FF80380000000
      F00FF00080010001E007000080010001E001000080010001C001000080010001
      C001000080010001C00300008001000180030000800100018007000080010001
      0007000083A103818007000083E103C1800F000083E103C1C00F800083FF03FF
      F01FC00183FF03FFFCFFC007BFFF3FFF00000000000000000000000000000000
      000000000000}
  end
end