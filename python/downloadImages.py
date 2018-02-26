#!/usr/bin/python

import requests
import shutil
from xml.dom import minidom

imagesUrl = 'https://builder.oncontrols.com/iruleweb/downloadImages?handset=2361514073'
imageUrl = 'https://builder.oncontrols.com/iruleweb/downloadImage?image='

cookies = dict(JSESSIONID='5hkgIvXKbJasPugI_W93Jg', SACSID='AJKiYcF-WegwfNp3u5y0c65d60e0SC_Y7qlNx_AJYe0PtxjTTFlumTynYjbeUa-yFTaBr0LfP14CXQZdwAuXtyA9L5XDNoDNtj0p5kDiUcIurNKPk0AC9n2zu1EgcJ6N9OAFifcqtBrv2NCYrIKz5ayQ3Eb7g-e_MEDUsaWx1t020kLS4Zg7BX88jpDyNsbVckSrlLA8VH17i2WNEvPr_y8_i-EWocuy9on21gKesj-LHpm39VtC0KNxnYrnUWngtsAM_xOrvNNIdWdkl8BAv37WUU_pNUL8xzAskYlMzAORiJ5UgIjqsyyQLt_hI8LTA87UpjSCG8f--g5NThIlRMTW-cThjtAV_Zsnke8BpQigCuG3cIkU-FLck04AKODV_NC_-l0mAZgoKfMQAgACtzJWHbQucfv9HV5vN9FeqF2hGaNUnf0hfBVy5HriSgnKJw90Vet_9KchV66ox0qmIQ4yNqefhSxTAEq1SI6tdveNhqlibBMiJ-R-b6Xi-glkl5-3ODWKan534aRxapkx1PWkTvsiM5QhqgN3u07uSjRLSQT-TAvs-3_y-rU1ko3_dYtMfElwDqWz0q5Ow6toTFl9jYdHqGc7glg3c4LAAP8KZJxvwUCVZ0WM2RE3f2b74sXrlTihdGH9blENWOzHXSsJpBHijMsrRBsvz2bWtOsmNI5swTNwkinRsF6_TfhI-iHyc4qzD8E_NtEmgVl9OT5TH8ADiAZpGFDvXsIua6EDDqRtaD8Nkp3a-plksli3WdlrM-GaKEcfeL2TETGGQFzc2kNdQNXu7QCL82BpfSFA0zbFk017W3qRwqipKGEYi6aIdcNZEW2UEV8BCpvcSvhihgrONUOBnneR95rLJWK5ihoG6KeXrKyxWdhkVDy2guFwMDzO-HBRn_VmjCyfl8pZYyuuIFQWMDwEs5hL2ZVVqEsGUEfiNl70T0vQqJwgsCsdkbSoCfm_MTDGEMCNj_4AAvEYWD0v1x581CFvM1rV4TPlqJ8JPceCdj-gp1Oz-ir0CblCDZ_q7UPjbBzTeIz0TNc519A1x-08chaLuZFBoXGrNILY9rDIwqjVZailYf87ETn9Ne1Z')

r = requests.get(imagesUrl, cookies=cookies)

xmldoc = minidom.parseString(r.text)
del r

imagelist = xmldoc.getElementsByTagName('Image')
for i in imagelist:
	imageId = i.attributes['id'].value
	print "downloading image: " + imageId

	r = requests.get(imageUrl + imageId, cookies=cookies, stream=True)
	with open(imageId + '.png', 'wb') as out_file:
		shutil.copyfileobj(r.raw, out_file)
	del r
