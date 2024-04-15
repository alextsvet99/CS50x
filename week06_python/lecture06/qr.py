import qrcode

image = qrcode.make("https://www.youtube.com/watch?v=ZLWQuYzE-PE")
image.save("qr.png", "PNG")
