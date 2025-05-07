import sys
from twilio.rest import Client

# Vérification des arguments
if len(sys.argv) < 3:
    print("Usage: send_sms.py <numero> <message>")
    sys.exit(1)

phone_number = sys.argv[1]  # Premier argument : numéro de téléphone
message_body = sys.argv[2]  # Deuxième argument : message

# Identifiants Twilio
account_sid = "AC22f67bdea79e9da5c2c261e305de93c6"
auth_token = "1cbd0eb629c8e6b120f0858eab046b23"
twilio_number = "+19704401143"

# Initialisation du client Twilio
client = Client(account_sid, auth_token)

# Envoi du SMS
message = client.messages.create(
    body=message_body,
    from_=twilio_number,
    to=phone_number
)

print("SMS envoyé avec succès ! ID:", message.sid)

