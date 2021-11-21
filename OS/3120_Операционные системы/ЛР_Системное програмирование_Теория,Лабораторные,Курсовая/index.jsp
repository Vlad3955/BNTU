<%@page errorPage="error.jsp"%>
<% 
// проверка на соответсвие IP-адреса маске

    String []ipClients = {"127.0.0.1","10.0.0.0-10.255.255.255","172.16.0.0-172.31.255.255","192.168.0.0-192.168.255.255"};
	//Интервалы сетей --mAxa--
                                boolean accessTrye = false;
                                for(int j=0;j<ipClients.length;j++){
                                    String ipAr[] = request.getRemoteAddr().split("\\.");
                                    int ip_1 = Integer.parseInt(ipAr[0]);
                                    int ip_2 = Integer.parseInt(ipAr[1]);
                                    int ip_3 = Integer.parseInt(ipAr[2]);
                                    int ip_4 = Integer.parseInt(ipAr[3]);
                                    String tempAr[] = ipClients[j].split("-");
                                    if(tempAr.length==2){
                                        String ipAccessStAr[] = tempAr[0].split("\\.");
                                        int ipAccessSt_1 = Integer.parseInt(ipAccessStAr[0]);
                                        int ipAccessSt_2 = Integer.parseInt(ipAccessStAr[1]);
                                        int ipAccessSt_3 = Integer.parseInt(ipAccessStAr[2]);
                                        int ipAccessSt_4 = Integer.parseInt(ipAccessStAr[3]);
                                        String ipAccessEnAr[] = tempAr[1].split("\\.");
                                        int ipAccessEn_1 = Integer.parseInt(ipAccessEnAr[0]);
                                        int ipAccessEn_2 = Integer.parseInt(ipAccessEnAr[1]);
                                        int ipAccessEn_3 = Integer.parseInt(ipAccessEnAr[2]);
                                        int ipAccessEn_4 = Integer.parseInt(ipAccessEnAr[3]);
                                        if((ip_1 >= ipAccessSt_1 && ip_1 <= ipAccessEn_1) && (ip_2 >= ipAccessSt_2 && ip_2 <= ipAccessEn_2) && (ip_3 >= ipAccessSt_3 && ip_3 <= ipAccessEn_3) && (ip_4 >= ipAccessSt_4 && ip_4 <= ipAccessEn_4)){
                                            accessTrye=true;
                                        }
                                    }else{
                                        String ipAccessAr[] = tempAr[0].split("\\.");
                                        int ipAccess_1 = Integer.parseInt(ipAccessAr[0]);
                                        int ipAccess_2 = Integer.parseInt(ipAccessAr[1]);
                                        int ipAccess_3 = Integer.parseInt(ipAccessAr[2]);
                                        int ipAccess_4 = Integer.parseInt(ipAccessAr[3]);
                                        if((ip_1 == ipAccess_1) && (ip_2 == ipAccess_2) && (ip_3 == ipAccess_3) && (ip_4 == ipAccess_4)){
                                            accessTrye=true;
                                        }
                                    }
								}

// если польхователь не из нашей сети, проверка логина/пароля
if ( accessTrye || !(session.getAttribute("OnlineUser_116608") == null) ) {
%>
<%@ include file="index.html"%>
<%} else {%>
	Вы не прошли авторизацию и поэтому не имеете права использования данного ресурса. Заавторизируйтесь на <a href="http://abitur.bsuir.unibel.by/index.jsp?resID=116608">главной странице системы доступа к ЭУМК</a>.
<%}%>